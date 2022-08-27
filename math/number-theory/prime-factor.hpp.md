---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/verify/aoj-ntl-1-a.test.cpp
    title: test/verify/aoj-ntl-1-a.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "Prime Factor(\u7D20\u56E0\u6570\u5206\u89E3)"
    links: []
  bundledCode: "#line 1 \"math/number-theory/prime-factor.hpp\"\n/**\n * @brief Prime\
    \ Factor(\u7D20\u56E0\u6570\u5206\u89E3)\n */\nmap< int64_t, int > prime_factor(int64_t\
    \ n) {\n  map< int64_t, int > ret;\n  for (int64_t i = 2; i * i <= n; i++) {\n\
    \    while (n % i == 0) {\n      ret[i]++;\n      n /= i;\n    }\n  }\n  if (n\
    \ != 1) ret[n] = 1;\n  return ret;\n}\n"
  code: "/**\n * @brief Prime Factor(\u7D20\u56E0\u6570\u5206\u89E3)\n */\nmap< int64_t,\
    \ int > prime_factor(int64_t n) {\n  map< int64_t, int > ret;\n  for (int64_t\
    \ i = 2; i * i <= n; i++) {\n    while (n % i == 0) {\n      ret[i]++;\n     \
    \ n /= i;\n    }\n  }\n  if (n != 1) ret[n] = 1;\n  return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/number-theory/prime-factor.hpp
  requiredBy: []
  timestamp: '2022-08-27 15:55:50+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/verify/aoj-ntl-1-a.test.cpp
documentation_of: math/number-theory/prime-factor.hpp
layout: document
redirect_from:
- /library/math/number-theory/prime-factor.hpp
- /library/math/number-theory/prime-factor.hpp.html
title: "Prime Factor(\u7D20\u56E0\u6570\u5206\u89E3)"
---
