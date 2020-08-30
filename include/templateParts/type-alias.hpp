#pragma once
#include <cstdint>
#include <functional>
#include <limits>
#include <queue>
#include <vector>

/**
 * @brief 型エイリアス
 */
using i64 = int64_t;
using u64 = uint64_t;
using usize = size_t;
using ld = long double;
template <class T>
using MaxHeap = std::priority_queue<T, std::vector<T>>;
template <class T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
