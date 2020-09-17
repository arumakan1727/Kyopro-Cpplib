#pragma once
#include <cstdint>

/**
 * @brief int-infinity (整数のデカイ値)
 * 2倍してもオーバーフローしない & memset()にも使える (需要ある？)
 */
constexpr std::int32_t INF = 0x3f3f3f3f;
constexpr std::int64_t LINF = 0x3f3f3f3f3f3f3f3fLL;
