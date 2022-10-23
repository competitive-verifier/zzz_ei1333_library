---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj-ntl-1-a.test.cpp
    title: test/verify/aoj-ntl-1-a.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/number-theory/prime-factor.hpp\"\nmap< int64_t, int\
    \ > prime_factor(int64_t n) {\n  map< int64_t, int > ret;\n  for(int64_t i = 2;\
    \ i * i <= n; i++) {\n    while(n % i == 0) {\n      ret[i]++;\n      n /= i;\n\
    \    }\n  }\n  if(n != 1) ret[n] = 1;\n  return ret;\n}\n"
  code: "map< int64_t, int > prime_factor(int64_t n) {\n  map< int64_t, int > ret;\n\
    \  for(int64_t i = 2; i * i <= n; i++) {\n    while(n % i == 0) {\n      ret[i]++;\n\
    \      n /= i;\n    }\n  }\n  if(n != 1) ret[n] = 1;\n  return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/number-theory/prime-factor.hpp
  requiredBy: []
  timestamp: '2022-10-23 21:27:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/aoj-ntl-1-a.test.cpp
documentation_of: math/number-theory/prime-factor.hpp
layout: document
title: "Prime Factor(\u7D20\u56E0\u6570\u5206\u89E3)"
---

# prime_factor

```
map< int64_t, int > prime_factor(int64_t n)
```

$n$ を素因数分解した結果を連想配列で返します。連想配列の添字は素因数、値は指数です。

## 制約

- $0 \le n$

## 計算量

- $O(\sqrt n)$
