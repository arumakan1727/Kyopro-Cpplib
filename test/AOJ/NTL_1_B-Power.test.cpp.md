---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Algorithm/doubling-pow.hpp
    title: "doubling-pow() (\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5)"
  - icon: ':heavy_check_mark:'
    path: Math/Modulo/mod-int.hpp
    title: "Mod-Int (\u30B3\u30F3\u30D1\u30A4\u30EB\u6642mod\u578B\u3068\u5B9F\u884C\
      \u6642mod\u578B)"
  - icon: ':heavy_check_mark:'
    path: Util/int-alias.hpp
    title: "int-alias (\u6574\u6570\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B
  bundledCode: "#line 1 \"test/AOJ/NTL_1_B-Power.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B\"\
    \n\n#include <iostream>\n#include <type_traits>\n\n#line 2 \"Math/Modulo/mod-int.hpp\"\
    \n#include <cstdint>\n#include <cassert>\n#line 5 \"Math/Modulo/mod-int.hpp\"\n\
    #include <limits>\n\n/**\n * @brief Mod-Int (\u30B3\u30F3\u30D1\u30A4\u30EB\u6642\
    mod\u578B\u3068\u5B9F\u884C\u6642mod\u578B)\n */\nnamespace internal {\n\ntemplate\
    \ <class ModHolder>\nclass ModInt {\nprivate:\n    int64_t value;\n\npublic:\n\
    \    constexpr ModInt() noexcept\n        : value(0) {}\n\n    constexpr ModInt(int64_t\
    \ v) noexcept\n        : value(ModInt::normalized(v)) {}\n\n    static constexpr\
    \ const ModInt raw(int64_t v) noexcept {\n        ModInt ret;\n        ret.value\
    \ = v;\n        return ret;\n    }\n\n    static constexpr ModInt nullopt() noexcept\
    \ { return ModInt::raw(std::numeric_limits<int64_t>::min()); }\n\n    constexpr\
    \ bool isNull() const noexcept { return *this == ModInt::nullopt(); }\n\n    static\
    \ constexpr int64_t mod() { return ModHolder::mod; }\n\n    static int64_t setMod(int64_t\
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
    #line 2 \"Algorithm/doubling-pow.hpp\"\n#include <cmath>\n#line 3 \"Util/int-alias.hpp\"\
    \n\n/**\n * @brief int-alias (\u6574\u6570\u578B\u306E\u30A8\u30A4\u30EA\u30A2\
    \u30B9)\n */\nusing i64 = int64_t;\nusing u64 = uint64_t;\n#line 4 \"Algorithm/doubling-pow.hpp\"\
    \n\n/**\n * @brief doubling-pow() (\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\
    )\n */\ntemplate <class Integer>\nconstexpr Integer doublingPow(const Integer&\
    \ n, const i64 expv) {\n    Integer ret = 1, square = n;\n    for (u64 p = std::abs(expv);\
    \ p; p >>= 1) {\n        if (p & 1) ret *= square;\n        square *= square;\n\
    \    }\n    return (expv < 0) ? (1 / ret) : ret;\n}\n#line 8 \"test/AOJ/NTL_1_B-Power.test.cpp\"\
    \n\nint main() {\n    using Mint = ModInt1000000007;\n\n    Mint m;\n    int n;\n\
    \    std::cin >> m >> n;\n\n    const auto ans1 = m.pow(n);\n    const auto ans2\
    \ = doublingPow(m, n);\n\n    static_assert(std::is_same_v<decltype(ans1), decltype(ans2)>);\n\
    \    assert(ans1 == ans2);\n\n    std::cout << ans1 << std::endl;\n\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B\"\
    \n\n#include <iostream>\n#include <type_traits>\n\n#include \"../../Math/Modulo/mod-int.hpp\"\
    \n#include \"../../Algorithm/doubling-pow.hpp\"\n\nint main() {\n    using Mint\
    \ = ModInt1000000007;\n\n    Mint m;\n    int n;\n    std::cin >> m >> n;\n\n\
    \    const auto ans1 = m.pow(n);\n    const auto ans2 = doublingPow(m, n);\n\n\
    \    static_assert(std::is_same_v<decltype(ans1), decltype(ans2)>);\n    assert(ans1\
    \ == ans2);\n\n    std::cout << ans1 << std::endl;\n\n    return 0;\n}\n"
  dependsOn:
  - Math/Modulo/mod-int.hpp
  - Algorithm/doubling-pow.hpp
  - Util/int-alias.hpp
  isVerificationFile: true
  path: test/AOJ/NTL_1_B-Power.test.cpp
  requiredBy: []
  timestamp: '2020-10-10 20:15:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/NTL_1_B-Power.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/NTL_1_B-Power.test.cpp
- /verify/test/AOJ/NTL_1_B-Power.test.cpp.html
title: test/AOJ/NTL_1_B-Power.test.cpp
---