#pragma once
#include <iostream>

/**
 * @brief 複数変数宣言をして同時に入力もする
 */
template <class T>
std::istream &operator,(std::istream &is, T &rhs) { return is >> rhs; }

#define var(type, ...) \
    type __VA_ARGS__;  \
    cin >> __VA_ARGS__
