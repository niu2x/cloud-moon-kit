#include <boost/predef.h>

#if BOOST_OS_LINUX
#include <arpa/inet.h>
#elif BOOST_OS_WINDOWS
#include <winsock.h>
#endif

#include <string.h>
#include <random>
#include <algorithm>

#include "protocol.h"

#define htonll(x) ((1==htonl(1)) ? (x) : ((uint64_t)htonl((x) & 0xFFFFFFFF) << 32) | htonl((x) >> 32))
#define ntohll(x) ((1==ntohl(1)) ? (x) : ((uint64_t)ntohl((x) & 0xFFFFFFFF) << 32) | ntohl((x) >> 32))

namespace yy::msg800 {

NetworkProtocol::NetworkProtocol()
{
}

NetworkProtocol::~NetworkProtocol()
{
}

ByteBuffer NoneNetworkProtocol::pack(const uint8_t* data_ptr, size_t len)
{
    return { data_ptr, data_ptr + len };
}

std::vector<ByteBuffer> NoneNetworkProtocol::unpack(const uint8_t* data_ptr, size_t len)
{
    return { {
        data_ptr,
        data_ptr + len,
    } };
}

XOR_NetworkProtocol::XOR_NetworkProtocol(uint8_t key)
: cipher_key_(key)
{
}

ByteBuffer XOR_NetworkProtocol::pack(const uint8_t* data_ptr, size_t len)
{
    ByteBuffer result(len);

    std::transform(data_ptr, data_ptr + len, result.begin(), [this](auto& c) {
        return c ^ cipher_key_;
    });

    return result;
}

std::vector<ByteBuffer> XOR_NetworkProtocol::unpack(const uint8_t* data_ptr, size_t len)
{
    ByteBuffer result(len);

    std::transform(data_ptr, data_ptr + len, result.begin(), [this](auto& c) {
        return c ^ cipher_key_;
    });

    return { std::move(result) };
}

BirdNetworkProtocol::BirdNetworkProtocol(const Crypto::Key& key, const Crypto::IV& iv)
: crypto_(key, iv)
{
    printf("key: ");
    for (int i = 0; i < 16; i++) {
        printf("%02x ", key[i]);
    }
    printf("\n");

    printf("iv: ");
    for (int i = 0; i < 16; i++) {
        printf("%02x ", iv[i]);
    }
    printf("\n");
}

const uint64_t MAGIC = 0x20240828;

ByteBuffer BirdNetworkProtocol::pack(const uint8_t* data_ptr, size_t len)
{
    auto     body     = crypto_.encrypt(data_ptr, len);
    uint64_t body_len = body.size();

    std::random_device              rd; // 真随机数种子（可能依赖硬件）
    std::mt19937                    gen(rd()); // Mersenne Twister 伪随机数生成器
    std::uniform_int_distribution<> dist(0, 16);

    ByteBuffer noise(dist(gen));
    std::generate(noise.begin(), noise.end(), [&dist, &gen]() { return dist(gen); });

    uint64_t   noise_len = noise.size();

    uint64_t total_len = noise_len + body_len + 16;

    uint64_t encrypt_total_len = total_len ^ MAGIC;
    uint64_t encrypt_noise_len = noise_len ^ MAGIC;

    ByteBuffer out;
    out.resize(total_len);

    uint8_t* write_ptr = out.data();

    encrypt_total_len = htonll(encrypt_total_len);
    encrypt_noise_len = htonll(encrypt_noise_len);

    memcpy(write_ptr, &encrypt_total_len, 8);
    write_ptr += 8;

    memcpy(write_ptr, &encrypt_noise_len, 8);
    write_ptr += 8;

    memcpy(write_ptr, noise.data(), noise_len);
    write_ptr += noise_len;

    memcpy(write_ptr, body.data(), body_len);

    return out;
}
std::vector<ByteBuffer> BirdNetworkProtocol::unpack(const uint8_t* data_ptr, size_t len)
{
    buffer_.insert(buffer_.end(), data_ptr, data_ptr + len);

    std::vector<ByteBuffer> result;

    do {
        if (buffer_.size() < 16) {
            break;
        }

        uint64_t encrypt_total_len;
        uint64_t encrypt_noise_len;

        const uint8_t* read_ptr = buffer_.data();
        memcpy(&encrypt_total_len, read_ptr, 8);
        memcpy(&encrypt_noise_len, read_ptr + 8, 8);

        encrypt_total_len = ntohll(encrypt_total_len);
        encrypt_noise_len = ntohll(encrypt_noise_len);

        uint64_t total_len = encrypt_total_len ^ MAGIC;
        uint64_t noise_len = encrypt_noise_len ^ MAGIC;

        uint64_t body_len = total_len - noise_len - 16;

        if (buffer_.size() < total_len) {
            break;
        }

        result.push_back(crypto_.decrypt(read_ptr + 16 + noise_len, body_len));

        buffer_.erase(buffer_.begin(), buffer_.begin() + total_len);

    } while (true);

    return result;
}

} // namespace yy::msg800