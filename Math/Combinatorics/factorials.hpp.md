---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/Modulo/mod-int.hpp
    title: "Mod-Int (\u30B3\u30F3\u30D1\u30A4\u30EB\u6642mod\u578B\u3068\u5B9F\u884C\
      \u6642mod\u578B)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/1501-Grid.test.cpp
    title: test/AOJ/1501-Grid.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "factorials (\u968E\u4E57, \u968E\u4E57\u306E\u9006\u5143, nCr,\
      \ nPr)"
    links: []
  bundledCode: "#line 2 \"Math/Combinatorics/factorials.hpp\"\n#include <cassert>\n\
    #include <vector>\n\n#line 2 \"Math/Modulo/mod-int.hpp\"\n#include <cstdint>\n\
    #line 4 \"Math/Modulo/mod-int.hpp\"\n#include <iostream>\n#include <limits>\n\n\
    /**\n * @brief Mod-Int (\u30B3\u30F3\u30D1\u30A4\u30EB\u6642mod\u578B\u3068\u5B9F\
    \u884C\u6642mod\u578B)\n */\nnamespace internal {\n\ntemplate <class ModHolder>\n\
    class ModInt {\nprivate:\n    int64_t value;\n\npublic:\n    constexpr ModInt()\
    \ noexcept\n        : value(0) {}\n\n    constexpr ModInt(int64_t v) noexcept\n\
    \        : value(ModInt::normalized(v)) {}\n\n    static constexpr const ModInt\
    \ raw(int64_t v) noexcept {\n        ModInt ret;\n        ret.value = v;\n   \
    \     return ret;\n    }\n\n    static constexpr ModInt nullopt() noexcept { return\
    \ ModInt::raw(std::numeric_limits<int64_t>::min()); }\n\n    constexpr bool isNull()\
    \ const noexcept { return *this == ModInt::nullopt(); }\n\n    static constexpr\
    \ int64_t mod() { return ModHolder::mod; }\n\n    static int64_t setMod(int64_t\
    \ m) noexcept {\n        assert(m >= 1);\n        return ModHolder::mod = m;\n\
    \    }\n\n    template <class T>\n    constexpr explicit operator T() const noexcept\
    \ {\n        return static_cast<T>(value);\n    }\n\n    constexpr int64_t val()\
    \ const noexcept { return value; }\n\n    constexpr ModInt& operator+=(const ModInt&\
    \ rhs) noexcept {\n        if ((value += rhs.value) >= mod()) value -= mod();\n\
    \        return *this;\n    }\n    constexpr ModInt& operator-=(const ModInt&\
    \ rhs) noexcept {\n        if ((value -= rhs.value) < 0) value += mod();\n   \
    \     return *this;\n    }\n    constexpr ModInt& operator*=(const ModInt& rhs)\
    \ noexcept {\n        (value *= rhs.value) %= mod();\n        return *this;\n\
    \    }\n    constexpr ModInt& operator/=(const ModInt& rhs) noexcept { return\
    \ *this *= rhs.inv(); }\n    constexpr const ModInt inv() const noexcept { return\
    \ ModInt(ModInt::inverse(value, mod())); }\n    constexpr const ModInt operator+()\
    \ const noexcept { return *this; }\n    constexpr const ModInt operator-() const\
    \ noexcept { return ModInt(-value); }\n\n    constexpr const ModInt pow(int64_t\
    \ expv) const noexcept {\n        int64_t ret = 1, square = value;\n        for\
    \ (uint64_t p = std::abs(expv); p; p >>= 1) {\n            if (p & 1) (ret *=\
    \ square) %= mod();\n            (square *= square) %= mod();\n        }\n   \
    \     return (expv < 0) ? (ModInt::raw(1) / ModInt::raw(ret)) : ModInt::raw(ret);\n\
    \    }\n\n    friend constexpr bool operator==(const ModInt& lhs, const ModInt&\
    \ rhs) noexcept { return lhs.value == rhs.value; }\n    friend constexpr bool\
    \ operator!=(const ModInt& lhs, const ModInt& rhs) noexcept { return lhs.value\
    \ != rhs.value; }\n    friend constexpr const ModInt operator+(const ModInt& lhs,\
    \ const ModInt& rhs) noexcept { return ModInt(lhs) += rhs; }\n    friend constexpr\
    \ const ModInt operator-(const ModInt& lhs, const ModInt& rhs) noexcept { return\
    \ ModInt(lhs) -= rhs; }\n    friend constexpr const ModInt operator*(const ModInt&\
    \ lhs, const ModInt& rhs) noexcept { return ModInt(lhs) *= rhs; }\n    friend\
    \ constexpr const ModInt operator/(const ModInt& lhs, const ModInt& rhs) noexcept\
    \ { return ModInt(lhs) /= rhs; }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const ModInt& x) {\n#ifdef LOCAL_DEBUG\n        if (x.isNull()) return os\
    \ << \"{nullopt}\";\n#endif\n        return os << x.value;\n    }\n\n    friend\
    \ std::istream& operator>>(std::istream& is, ModInt& x) {\n        is >> x.value;\n\
    \        x.value = ModInt::normalized(x.value);\n        return is;\n    }\n\n\
    private:\n    static constexpr int64_t normalized(int64_t n) {\n        n = (-mod()\
    \ <= n && n < mod() ? n : n % mod());\n        if (n < 0) n += mod();\n      \
    \  return n;\n    }\n\n    static constexpr int64_t inverse(int64_t a, int64_t\
    \ m) {\n        int64_t u = 0, v = 1;\n        while (a != 0) {\n            const\
    \ auto t = m / a;\n            static_cast<void>(m -= t * a), std::swap(m, a);\n\
    \            static_cast<void>(u -= t * v), std::swap(u, v);\n        }\n    \
    \    assert(m == 1);\n        return u;\n    }\n};\n\ntemplate <int64_t Mod>\n\
    struct StaticModHolder {\n    static constexpr int64_t mod = Mod;\n};\n\ntemplate\
    \ <int ID>\nstruct DynamicModHolder {\n    static int64_t mod;\n};\ntemplate <int\
    \ ID>\nint64_t DynamicModHolder<ID>::mod;\n\n}  // namespace internal\n\ntemplate\
    \ <int64_t Mod>\nusing StaticModInt = internal::ModInt<internal::StaticModHolder<Mod>>;\n\
    \nusing ModInt1000000007 = StaticModInt<int(1e9) + 7>;\nusing ModInt998244353\
    \ = StaticModInt<998244353>;\n\ntemplate <int ID>\nusing DynamicModInt = internal::ModInt<internal::DynamicModHolder<ID>>;\n\
    #line 6 \"Math/Combinatorics/factorials.hpp\"\n\n/**\n * @brief factorials (\u968E\
    \u4E57, \u968E\u4E57\u306E\u9006\u5143, nCr, nPr)\n */\ntemplate <class Mint>\n\
    struct Factorials {\npublic:\n    using value_type = Mint;\n    static constexpr\
    \ size_t MAX_N = std::min<size_t>(1e7, Mint::mod()) + 1;\n\nprivate:\n    mutable\
    \ std::vector<value_type> m_fact, m_finv;\n\npublic:\n    Factorials() {\n   \
    \     m_fact.reserve(MAX_N);\n        m_finv.reserve(MAX_N);\n        m_fact.resize(2,\
    \ value_type::raw(1));   // m_fact[0] = m_fact[1] = 1\n        m_finv.resize(2,\
    \ value_type::raw(1));   // m_finv[0] = m_finv[1] = 1\n    }\n\n    void preCalc(size_t\
    \ n) const {\n        if (n < m_fact.size()) return;\n        const size_t l =\
    \ m_fact.size();\n        const size_t r = n + 1;\n        m_fact.resize(r), m_finv.resize(r);\n\
    \        for (size_t i = l; i < r; ++i) m_fact[i] = m_fact[i - 1] * i;\n     \
    \   m_finv[r - 1] = m_fact[r - 1].inv();\n        for (size_t i = r - 1; i > l;\
    \ --i) m_finv[i - 1] = m_finv[i] * i;\n    }\n\n    const value_type fact(int\
    \ i) const { return preCalc(i), m_fact[i]; }\n    const value_type finv(int i)\
    \ const { return preCalc(i), m_finv[i]; }\n\n    const value_type C(int n, int\
    \ r) const {\n        if (r < 0 || n < r) return value_type::raw(0);\n       \
    \ return preCalc(n), m_fact[n] * m_finv[r] * m_finv[n - r];\n    }\n\n    const\
    \ value_type P(int n, int r) const {\n        if (r < 0 || n < r) return value_type::raw(0);\n\
    \        return preCalc(n), m_fact[n] * m_finv[n - r];\n    }\n\n    const value_type\
    \ H(int n, int r) const {\n        if (n < 0 || r < 0) return value_type::raw(0);\n\
    \        if (n == 0 && r == 0) return value_type::raw(1);\n        return C(n\
    \ + r - 1, r);\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n\n#include \"../Modulo/mod-int.hpp\"\
    \n\n/**\n * @brief factorials (\u968E\u4E57, \u968E\u4E57\u306E\u9006\u5143, nCr,\
    \ nPr)\n */\ntemplate <class Mint>\nstruct Factorials {\npublic:\n    using value_type\
    \ = Mint;\n    static constexpr size_t MAX_N = std::min<size_t>(1e7, Mint::mod())\
    \ + 1;\n\nprivate:\n    mutable std::vector<value_type> m_fact, m_finv;\n\npublic:\n\
    \    Factorials() {\n        m_fact.reserve(MAX_N);\n        m_finv.reserve(MAX_N);\n\
    \        m_fact.resize(2, value_type::raw(1));   // m_fact[0] = m_fact[1] = 1\n\
    \        m_finv.resize(2, value_type::raw(1));   // m_finv[0] = m_finv[1] = 1\n\
    \    }\n\n    void preCalc(size_t n) const {\n        if (n < m_fact.size()) return;\n\
    \        const size_t l = m_fact.size();\n        const size_t r = n + 1;\n  \
    \      m_fact.resize(r), m_finv.resize(r);\n        for (size_t i = l; i < r;\
    \ ++i) m_fact[i] = m_fact[i - 1] * i;\n        m_finv[r - 1] = m_fact[r - 1].inv();\n\
    \        for (size_t i = r - 1; i > l; --i) m_finv[i - 1] = m_finv[i] * i;\n \
    \   }\n\n    const value_type fact(int i) const { return preCalc(i), m_fact[i];\
    \ }\n    const value_type finv(int i) const { return preCalc(i), m_finv[i]; }\n\
    \n    const value_type C(int n, int r) const {\n        if (r < 0 || n < r) return\
    \ value_type::raw(0);\n        return preCalc(n), m_fact[n] * m_finv[r] * m_finv[n\
    \ - r];\n    }\n\n    const value_type P(int n, int r) const {\n        if (r\
    \ < 0 || n < r) return value_type::raw(0);\n        return preCalc(n), m_fact[n]\
    \ * m_finv[n - r];\n    }\n\n    const value_type H(int n, int r) const {\n  \
    \      if (n < 0 || r < 0) return value_type::raw(0);\n        if (n == 0 && r\
    \ == 0) return value_type::raw(1);\n        return C(n + r - 1, r);\n    }\n};\n"
  dependsOn:
  - Math/Modulo/mod-int.hpp
  isVerificationFile: false
  path: Math/Combinatorics/factorials.hpp
  requiredBy: []
  timestamp: '2020-10-24 20:26:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/1501-Grid.test.cpp
documentation_of: Math/Combinatorics/factorials.hpp
layout: document
redirect_from:
- /library/Math/Combinatorics/factorials.hpp
- /library/Math/Combinatorics/factorials.hpp.html
title: "factorials (\u968E\u4E57, \u968E\u4E57\u306E\u9006\u5143, nCr, nPr)"
---