---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/binomial.md
    document_title: "Binomial(\u4E8C\u9805\u4FC2\u6570)"
    links: []
  bundledCode: "#line 1 \"math/combinatorics/binomial.hpp\"\n/**\n * @brief Binomial(\u4E8C\
    \u9805\u4FC2\u6570)\n * @docs docs/binomial.md\n */\ntemplate < typename T >\n\
    T binomial(int64_t N, int64_t K) {\n  if (K < 0 || N < K) return 0;\n  static\
    \ vector< T > invs;\n  if (invs.size() < K + 1) {\n    int pre_sz = max(1, (int)invs.size());\n\
    \    invs.resize(K + 1);\n    for (int i = pre_sz; i <= K; i++) {\n      invs[i]\
    \ = T(1) / i;\n    }\n  }\n  T ret = 1;\n  for (int64_t i = 1; i <= K; ++i) {\n\
    \    ret *= N;\n    N--;\n    ret *= invs[i];\n  }\n  return ret;\n}\n"
  code: "/**\n * @brief Binomial(\u4E8C\u9805\u4FC2\u6570)\n * @docs docs/binomial.md\n\
    \ */\ntemplate < typename T >\nT binomial(int64_t N, int64_t K) {\n  if (K < 0\
    \ || N < K) return 0;\n  static vector< T > invs;\n  if (invs.size() < K + 1)\
    \ {\n    int pre_sz = max(1, (int)invs.size());\n    invs.resize(K + 1);\n   \
    \ for (int i = pre_sz; i <= K; i++) {\n      invs[i] = T(1) / i;\n    }\n  }\n\
    \  T ret = 1;\n  for (int64_t i = 1; i <= K; ++i) {\n    ret *= N;\n    N--;\n\
    \    ret *= invs[i];\n  }\n  return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/combinatorics/binomial.hpp
  requiredBy: []
  timestamp: '2022-08-27 15:55:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/combinatorics/binomial.hpp
layout: document
redirect_from:
- /library/math/combinatorics/binomial.hpp
- /library/math/combinatorics/binomial.hpp.html
title: "Binomial(\u4E8C\u9805\u4FC2\u6570)"
---
## 概要

二項係数 ${}_n \mathrm{C} _k$ を $\displaystyle \frac {k(k-1)\dots (n-k+1)} {k(k-1)\dots 1}$ を利用して求める.

$k$ が小さい時に有効.

## 使い方

* `binomial(N, K)`: ${}_n \mathrm{C} _k$ を返す. 

## 計算量

* $O(K \log K)$

ただし逆元が $O(1)$ で求まる場合 $O(K)$
