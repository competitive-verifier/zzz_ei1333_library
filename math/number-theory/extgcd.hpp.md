---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/verify/aoj-ntl-1-e.test.cpp
    title: test/verify/aoj-ntl-1-e.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/extgcd.md
    document_title: "Extgcd(\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\
      \u4E92\u9664\u6CD5)"
    links: []
  bundledCode: "#line 1 \"math/number-theory/extgcd.hpp\"\n/**\n * @brief Extgcd(\u62E1\
    \u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5)\n * @docs\
    \ docs/extgcd.md\n */\ntemplate< typename T >\nT extgcd(T a, T b, T &x, T &y)\
    \ {\n  T d = a;\n  if(b != 0) {\n    d = extgcd(b, a % b, y, x);\n    y -= (a\
    \ / b) * x;\n  } else {\n    x = 1;\n    y = 0;\n  }\n  return d;\n}\n"
  code: "/**\n * @brief Extgcd(\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\
    \u4E92\u9664\u6CD5)\n * @docs docs/extgcd.md\n */\ntemplate< typename T >\nT extgcd(T\
    \ a, T b, T &x, T &y) {\n  T d = a;\n  if(b != 0) {\n    d = extgcd(b, a % b,\
    \ y, x);\n    y -= (a / b) * x;\n  } else {\n    x = 1;\n    y = 0;\n  }\n  return\
    \ d;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/number-theory/extgcd.hpp
  requiredBy: []
  timestamp: '2022-07-05 18:16:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/verify/aoj-ntl-1-e.test.cpp
documentation_of: math/number-theory/extgcd.hpp
layout: document
redirect_from:
- /library/math/number-theory/extgcd.hpp
- /library/math/number-theory/extgcd.hpp.html
title: "Extgcd(\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5\
  )"
---
## 概要

$a, b$ が与えられたとき, $ax + by = \gcd(a, b)$ を満たす整数解 $(x, y)$ を求める.

## 使い方

* `extgcd(a, b, x, y)`: $\gcd(a, b)$ を返す. $(x, y)$ には $ax + by = \gcd(a, b)$ を満たす整数解が格納される. 整数解は複数考えられるが, $\|x\| + \|y\|$ が最小のものを求めている.

## 計算量

* $O(\log {\min(a, b)})$
