---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj-alds-1-1-c.test.cpp
    title: test/verify/aoj-alds-1-1-c.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/number-theory/is-prime.hpp\"\nbool is_prime(int64_t\
    \ x) {\n  for(int64_t i = 2; i * i <= x; i++) {\n    if(x % i == 0) return false;\n\
    \  }\n  return true;\n}\n"
  code: "bool is_prime(int64_t x) {\n  for(int64_t i = 2; i * i <= x; i++) {\n   \
    \ if(x % i == 0) return false;\n  }\n  return true;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/number-theory/is-prime.hpp
  requiredBy: []
  timestamp: '2022-09-11 00:53:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/aoj-alds-1-1-c.test.cpp
documentation_of: math/number-theory/is-prime.hpp
layout: document
title: "Is Prime(\u7D20\u6570\u5224\u5B9A)"
---

# is_prime

```
bool is_prime(int64_t x)
```

$x$ が素数なら `true`、素数でなければ `false` を返します。

## 制約

- $0 \le x$

## 計算量

- $O(\sqrt x)$
