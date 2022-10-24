---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/number-theory/prime-count.hpp
    title: "Prime Count(\u7D20\u6570\u306E\u500B\u6570)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-counting-primes.test.cpp
    title: test/verify/yosupo-counting-primes.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-kth-root-integer.test.cpp
    title: test/verify/yosupo-kth-root-integer.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/number-theory/kth-root-integer.hpp\"\nuint64_t kth_root_integer(uint64_t\
    \ a, int k) {\n  if(k == 1) return a;\n  auto check = [&](uint32_t x) {\n    uint64_t\
    \ mul = 1;\n    for(int j = 0; j < k; j++) {\n      if(__builtin_mul_overflow(mul,\
    \ x, &mul)) return false;\n    }\n    return mul <= a;\n  };\n  uint64_t ret =\
    \ 0;\n  for(int i = 31; i >= 0; i--) {\n    if(check(ret | (1u << i))) ret |=\
    \ 1u << i;\n  }\n  return ret;\n}\n"
  code: "uint64_t kth_root_integer(uint64_t a, int k) {\n  if(k == 1) return a;\n\
    \  auto check = [&](uint32_t x) {\n    uint64_t mul = 1;\n    for(int j = 0; j\
    \ < k; j++) {\n      if(__builtin_mul_overflow(mul, x, &mul)) return false;\n\
    \    }\n    return mul <= a;\n  };\n  uint64_t ret = 0;\n  for(int i = 31; i >=\
    \ 0; i--) {\n    if(check(ret | (1u << i))) ret |= 1u << i;\n  }\n  return ret;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: math/number-theory/kth-root-integer.hpp
  requiredBy:
  - math/number-theory/prime-count.hpp
  timestamp: '2022-10-23 21:05:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/yosupo-kth-root-integer.test.cpp
  - test/verify/yosupo-counting-primes.test.cpp
documentation_of: math/number-theory/kth-root-integer.hpp
layout: document
title: Kth Root Integer
---

# kth_root_integer

```
uint64_t kth_root_integer(uint64_t a, int k)
```

$\textrm{floor}{(a^{\frac {1} {k}})}$ を返します。

## 制約

- $0 \leq a \lt 2^{64}$
- $1 \leq k \leq 64$

## 計算量

- $O(k \log \log a)$
