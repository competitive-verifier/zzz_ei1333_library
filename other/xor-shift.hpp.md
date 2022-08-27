---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/xor-shift.md
    document_title: Xor-Shift
    links: []
  bundledCode: "#line 1 \"other/xor-shift.hpp\"\n/**\n * @brief Xor-Shift\n * @docs\
    \ docs/xor-shift.md\n */\nstruct XorShift {\n private:\n  constexpr static double\
    \ R = 1.0 / 0xffffffff;\n  uint64_t x;\n\n public:\n  explicit XorShift(uint64_t\
    \ seed = 88172645463325252ull): x(seed) {}\n\n  template < typename T = uint64_t\
    \ >\n  inline T get() { // [0, 2^64)\n    x ^= x << 7ull;\n    x ^= x >> 9ull;\n\
    \    return x;\n  }\n\n  inline uint32_t get(uint32_t r) { // [0, r)\n    return\
    \ ((uint64_t)get< uint32_t >() * r) >> 32ull;\n  }\n\n  inline uint32_t get(uint32_t\
    \ l, uint32_t r) { // [l, r)\n    return l + get(r - l);\n  }\n\n  inline double\
    \ probability() { // [0.0, 1.0]\n    return get< uint32_t >() * R;\n  }\n};\n"
  code: "/**\n * @brief Xor-Shift\n * @docs docs/xor-shift.md\n */\nstruct XorShift\
    \ {\n private:\n  constexpr static double R = 1.0 / 0xffffffff;\n  uint64_t x;\n\
    \n public:\n  explicit XorShift(uint64_t seed = 88172645463325252ull): x(seed)\
    \ {}\n\n  template < typename T = uint64_t >\n  inline T get() { // [0, 2^64)\n\
    \    x ^= x << 7ull;\n    x ^= x >> 9ull;\n    return x;\n  }\n\n  inline uint32_t\
    \ get(uint32_t r) { // [0, r)\n    return ((uint64_t)get< uint32_t >() * r) >>\
    \ 32ull;\n  }\n\n  inline uint32_t get(uint32_t l, uint32_t r) { // [l, r)\n \
    \   return l + get(r - l);\n  }\n\n  inline double probability() { // [0.0, 1.0]\n\
    \    return get< uint32_t >() * R;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: other/xor-shift.hpp
  requiredBy: []
  timestamp: '2022-08-27 15:55:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/xor-shift.hpp
layout: document
redirect_from:
- /library/other/xor-shift.hpp
- /library/other/xor-shift.hpp.html
title: Xor-Shift
---
## 概要
Xorshift は擬似乱数生成法の一つである.

周期が $2^{64}-1$ となる実装を示した.

* `XorShift(seed)`: シード値 `seed` で初期化する.
* `get()`: $[0, 2^{64})$ で生成した乱数を返す.
* `get(r)`: $[0, r)$ で生成した乱数を返す. `r` は32bit整数に限る. 64bitで生成したい場合は例えば `get()` を `r` で割った余りを求めるとよい.
* `get(l, r)`: $[l, r)$ で生成した乱数を返す.
* `probability()`: $[0.0, 1.0)$ で生成した乱数(実数)を返す.
