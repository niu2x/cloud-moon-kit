#pragma once

#include <cstdint>

namespace yy {

using ByteBuffer = std::vector<uint8_t>;

class AES_Crypto {
public:
    using Key = uint8_t[16];
    using IV  = uint8_t[16];

    AES_Crypto(const Key& key, const IV& iv);

    ByteBuffer encrypt(const uint8_t* data_ptr, size_t len) const;
    ByteBuffer decrypt(const uint8_t* data_ptr, size_t len) const;

private:
    Key key_;
    IV  iv_;
};

} // namespace yy
