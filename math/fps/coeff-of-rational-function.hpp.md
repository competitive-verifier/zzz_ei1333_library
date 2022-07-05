---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: math/fps/kth-term-of-linearly-recurrent-sequence.hpp
    title: Kth Term of Linearly Recurrent Sequence
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/verify/yosupo-kth-term-of-linearly-recurrent-sequence.test.cpp
    title: test/verify/yosupo-kth-term-of-linearly-recurrent-sequence.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/coeff-of-rational-function.md
    document_title: Coeff of Rational Function
    links: []
  bundledCode: "#line 1 \"math/fps/coeff-of-rational-function.hpp\"\n/**\n * @brief\
    \ Coeff of Rational Function\n * @docs docs/coeff-of-rational-function.md\n */\n\
    template< template< typename > class FPS, typename Mint >\nMint coeff_of_rational_function(FPS<\
    \ Mint > P, FPS< Mint > Q, int64_t k) {\n  // compute the coefficient [x^k] P/Q\
    \ of rational power series\n  Mint ret = 0;\n  if(P.size() >= Q.size()) {\n  \
    \  auto R = P / Q;\n    P -= R * Q;\n    P.shrink();\n    if(k < (int) R.size())\
    \ ret += R[k];\n  }\n  if(P.empty()) return ret;\n  P.resize((int) Q.size() -\
    \ 1);\n  auto sub = [&](const FPS< Mint > &as, bool odd) {\n    FPS< Mint > bs((as.size()\
    \ + !odd) / 2);\n    for(int i = odd; i < (int) as.size(); i += 2) bs[i >> 1]\
    \ = as[i];\n    return bs;\n  };\n  while(k > 0) {\n    auto Q2(Q);\n    for(int\
    \ i = 1; i < (int) Q2.size(); i += 2) Q2[i] = -Q2[i];\n    P = sub(P * Q2, k &\
    \ 1);\n    Q = sub(Q * Q2, 0);\n    k >>= 1;\n  }\n  return ret + P[0];\n}\n"
  code: "/**\n * @brief Coeff of Rational Function\n * @docs docs/coeff-of-rational-function.md\n\
    \ */\ntemplate< template< typename > class FPS, typename Mint >\nMint coeff_of_rational_function(FPS<\
    \ Mint > P, FPS< Mint > Q, int64_t k) {\n  // compute the coefficient [x^k] P/Q\
    \ of rational power series\n  Mint ret = 0;\n  if(P.size() >= Q.size()) {\n  \
    \  auto R = P / Q;\n    P -= R * Q;\n    P.shrink();\n    if(k < (int) R.size())\
    \ ret += R[k];\n  }\n  if(P.empty()) return ret;\n  P.resize((int) Q.size() -\
    \ 1);\n  auto sub = [&](const FPS< Mint > &as, bool odd) {\n    FPS< Mint > bs((as.size()\
    \ + !odd) / 2);\n    for(int i = odd; i < (int) as.size(); i += 2) bs[i >> 1]\
    \ = as[i];\n    return bs;\n  };\n  while(k > 0) {\n    auto Q2(Q);\n    for(int\
    \ i = 1; i < (int) Q2.size(); i += 2) Q2[i] = -Q2[i];\n    P = sub(P * Q2, k &\
    \ 1);\n    Q = sub(Q * Q2, 0);\n    k >>= 1;\n  }\n  return ret + P[0];\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/fps/coeff-of-rational-function.hpp
  requiredBy:
  - math/fps/kth-term-of-linearly-recurrent-sequence.hpp
  timestamp: '2022-07-05 18:16:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/verify/yosupo-kth-term-of-linearly-recurrent-sequence.test.cpp
documentation_of: math/fps/coeff-of-rational-function.hpp
layout: document
redirect_from:
- /library/math/fps/coeff-of-rational-function.hpp
- /library/math/fps/coeff-of-rational-function.hpp.html
title: Coeff of Rational Function
---
## 概要

$K$ 次多項式 $P(x), Q(x)$ に対して $\displaystyle [x^N] \frac{P(x)}{Q(x)}$ を Bostan-Mori algorithm によって計算する。

## 計算量

$O(K \log K \log N)$
