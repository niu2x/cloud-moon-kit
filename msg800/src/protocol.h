#pragma once

#include <vector>
#include <memory>
#include <cstdint>
#include <ranges>

#include <yy/crypto.h>

namespace yy::msg800 {

using ByteBuffer = std::vector<uint8_t>;

//
class NetworkProtocol {
public:
    NetworkProtocol();
    virtual ~NetworkProtocol();

    virtual ByteBuffer              pack(const uint8_t* data_ptr, size_t len)   = 0;
    virtual std::vector<ByteBuffer> unpack(const uint8_t* data_ptr, size_t len) = 0;
};

class NoneNetworkProtocol : public NetworkProtocol {
public:
    ByteBuffer              pack(const uint8_t* data_ptr, size_t len) override;
    std::vector<ByteBuffer> unpack(const uint8_t* data_ptr, size_t len) override;
};

class XOR_NetworkProtocol : public NetworkProtocol {
public:
    explicit XOR_NetworkProtocol(uint8_t cipher_key);
    ByteBuffer              pack(const uint8_t* data_ptr, size_t len) override;
    std::vector<ByteBuffer> unpack(const uint8_t* data_ptr, size_t len) override;

private:
    uint8_t cipher_key_;
};

class BirdNetworkProtocol : public NetworkProtocol {
public:
    using Crypto = AES_Crypto;

    BirdNetworkProtocol(const Crypto::Key& key, const Crypto::IV& iv);
    ByteBuffer              pack(const uint8_t* data_ptr, size_t len) override;
    std::vector<ByteBuffer> unpack(const uint8_t* data_ptr, size_t len) override;

private:
    Crypto crypto_;

    ByteBuffer buffer_;
};

} // namespace yy::msg800