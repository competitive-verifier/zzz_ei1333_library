---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/verify/yosupo-sum-of-floor-of-linear.test.cpp
    title: test/verify/yosupo-sum-of-floor-of-linear.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/sum-of-floor-of-linear.md
    document_title: "Sum of Floor of Linear(\u4E00\u6B21\u95A2\u6570\u306E\u5E8A\u95A2\
      \u6570\u306E\u548C)"
    links: []
  bundledCode: "#line 1 \"math/number-theory/sum-of-floor-of-linear.hpp\"\n/**\n *\
    \ @brief Sum of Floor of Linear(\u4E00\u6B21\u95A2\u6570\u306E\u5E8A\u95A2\u6570\
    \u306E\u548C)\n * @docs docs/sum-of-floor-of-linear.md\n */\ntemplate< typename\
    \ T >\nT sum_of_floor_of_linear(const T &n, const T &m, T a, T b) {\n  T ret =\
    \ 0;\n  if(a >= m) ret += (n - 1) * n * (a / m) / 2, a %= m;\n  if(b >= m) ret\
    \ += n * (b / m), b %= m;\n  T y = (a * n + b) / m;\n  if(y == 0) return ret;\n\
    \  T x = y * m - b;\n  ret += (n - (x + a - 1) / a) * y;\n  ret += sum_of_floor_of_linear(y,\
    \ a, m, (a - x % a) % a);\n  return ret;\n}\n"
  code: "/**\n * @brief Sum of Floor of Linear(\u4E00\u6B21\u95A2\u6570\u306E\u5E8A\
    \u95A2\u6570\u306E\u548C)\n * @docs docs/sum-of-floor-of-linear.md\n */\ntemplate<\
    \ typename T >\nT sum_of_floor_of_linear(const T &n, const T &m, T a, T b) {\n\
    \  T ret = 0;\n  if(a >= m) ret += (n - 1) * n * (a / m) / 2, a %= m;\n  if(b\
    \ >= m) ret += n * (b / m), b %= m;\n  T y = (a * n + b) / m;\n  if(y == 0) return\
    \ ret;\n  T x = y * m - b;\n  ret += (n - (x + a - 1) / a) * y;\n  ret += sum_of_floor_of_linear(y,\
    \ a, m, (a - x % a) % a);\n  return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/number-theory/sum-of-floor-of-linear.hpp
  requiredBy: []
  timestamp: '2022-07-05 18:16:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/verify/yosupo-sum-of-floor-of-linear.test.cpp
documentation_of: math/number-theory/sum-of-floor-of-linear.hpp
layout: document
redirect_from:
- /library/math/number-theory/sum-of-floor-of-linear.hpp
- /library/math/number-theory/sum-of-floor-of-linear.hpp.html
title: "Sum of Floor of Linear(\u4E00\u6B21\u95A2\u6570\u306E\u5E8A\u95A2\u6570\u306E\
  \u548C)"
---
## 概要

$n, m, a, b$ が与えられたとき, $\displaystyle \sum_{i=0}^{n-1} \textrm{floor}{(\frac {a \times i + b} {m})}$ を求める.

## 使い方

* `sum_of_floor_of_linear(n, m, a, b)`: $\displaystyle \sum_{i=0}^{n-1} \textrm{floor}{(\frac {a \times i + b} {m})}$ を返す.

## 計算量

* $O(\log (n + m + a + b))$
