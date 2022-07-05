---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/verify/aoj-alds-1-1-c.test.cpp
    title: test/verify/aoj-alds-1-1-c.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
  timestamp: '2022-07-05 18:16:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/verify/aoj-alds-1-1-c.test.cpp
documentation_of: math/number-theory/is-prime.hpp
layout: document
redirect_from:
- /library/math/number-theory/is-prime.hpp
- /library/math/number-theory/is-prime.hpp.html
title: math/number-theory/is-prime.hpp
---
