#include <string.h>
#include <vector>
#include <stdexcept>

#include <openssl/evp.h>
#include <openssl/err.h>

#include <yy/crypto.h>
#include <yy/log.h>

namespace yy {

static void throw_openssl_error()
{
    auto err = ERR_get_error();
    char buf[256];
    ERR_error_string_n(err, buf, sizeof(buf));
    panic(buf);
}

AES_Crypto::AES_Crypto(const Key& key, const IV& iv)
{
    memcpy(key_, key, 16);
    memcpy(iv_, iv, 16);
}

ByteBuffer AES_Crypto::encrypt(const uint8_t* data_ptr, size_t data_len) const
{
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();

    ByteBuffer out(data_len + 16); // extra block for padding
    int        len = 0, total_len = 0;

    if (EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key_, iv_) != 1) {
        throw_openssl_error();
    }

    if (EVP_EncryptUpdate(ctx, out.data(), &len, data_ptr, data_len) != 1) {
        throw_openssl_error();
    }

    total_len += len;

    if (EVP_EncryptFinal_ex(ctx, out.data() + total_len, &len) != 1){
        throw_openssl_error();
    }
    total_len += len;

    out.resize(total_len);

    EVP_CIPHER_CTX_free(ctx);
    return out;
}

ByteBuffer AES_Crypto::decrypt(const uint8_t* data_ptr, size_t data_len) const
{
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();

    ByteBuffer out(data_len); // decrypted size ≤ data_len
    int        len = 0, total_len = 0;

    if (EVP_DecryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key_, iv_) != 1) {
        throw_openssl_error();
    }

    if (EVP_DecryptUpdate(ctx, out.data(), &len, data_ptr, data_len) != 1) {
        throw_openssl_error();
    }

    total_len += len;

    if (EVP_DecryptFinal_ex(ctx, out.data() + total_len, &len) != 1){
        // LOG(error) << "err final";
        throw_openssl_error();
    }

    total_len += len;
    out.resize(total_len);

    EVP_CIPHER_CTX_free(ctx);
    return out;
}

} // namespace yy
