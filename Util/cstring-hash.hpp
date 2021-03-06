#pragma once

#include <cstdint>

/**
 * @brief cstringHash() ヌル文字終端された文字列から32bitハッシュ値を生成する(constexpr)
 * @see https://en.wikipedia.org/wiki/Jenkins_hash_function
 */
constexpr uint32_t cstringHash(const char* s) {
    uint32_t hashv = 0;
    while (*s != '\0') {
        hashv += *s++;
        hashv += hashv << 10;
        hashv ^= hashv >> 6;
    }
    hashv += hashv << 3;
    hashv ^= hashv >> 11;
    hashv += hashv << 15;
    return hashv;
}
