---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj-2286.test.cpp
    title: test/verify/aoj-2286.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/euler-phi-table.md
    document_title: "Euler\u2019s Phi Table(\u30AA\u30A4\u30E9\u30FC\u306E\u03C6\u95A2\
      \u6570\u30C6\u30FC\u30D6\u30EB)"
    links: []
  bundledCode: "#line 1 \"math/number-theory/euler-phi-table.hpp\"\n/**\n * @brief\
    \ Euler\u2019s Phi Table(\u30AA\u30A4\u30E9\u30FC\u306E\u03C6\u95A2\u6570\u30C6\
    \u30FC\u30D6\u30EB)\n * @docs docs/euler-phi-table.md\n */\nvector< int > euler_phi_table(int\
    \ n) {\n  vector< int > euler(n + 1);\n  for(int i = 0; i <= n; i++) {\n    euler[i]\
    \ = i;\n  }\n  for(int i = 2; i <= n; i++) {\n    if(euler[i] == i) {\n      for(int\
    \ j = i; j <= n; j += i) {\n        euler[j] = euler[j] / i * (i - 1);\n     \
    \ }\n    }\n  }\n  return euler;\n}\n"
  code: "/**\n * @brief Euler\u2019s Phi Table(\u30AA\u30A4\u30E9\u30FC\u306E\u03C6\
    \u95A2\u6570\u30C6\u30FC\u30D6\u30EB)\n * @docs docs/euler-phi-table.md\n */\n\
    vector< int > euler_phi_table(int n) {\n  vector< int > euler(n + 1);\n  for(int\
    \ i = 0; i <= n; i++) {\n    euler[i] = i;\n  }\n  for(int i = 2; i <= n; i++)\
    \ {\n    if(euler[i] == i) {\n      for(int j = i; j <= n; j += i) {\n       \
    \ euler[j] = euler[j] / i * (i - 1);\n      }\n    }\n  }\n  return euler;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/number-theory/euler-phi-table.hpp
  requiredBy: []
  timestamp: '2022-09-11 00:53:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/aoj-2286.test.cpp
documentation_of: math/number-theory/euler-phi-table.hpp
layout: document
redirect_from:
- /library/math/number-theory/euler-phi-table.hpp
- /library/math/number-theory/euler-phi-table.hpp.html
title: "Euler\u2019s Phi Table(\u30AA\u30A4\u30E9\u30FC\u306E\u03C6\u95A2\u6570\u30C6\
  \u30FC\u30D6\u30EB)"
---
## 概要

正の整数 $n$ が与えられたとき, $1$ から $n$ までの自然数のうち $n$ と互いに素なものの個数 $\phi(n)$ を求める.

以下の式で効率的に求めることができる.

$\phi(n)=n\displaystyle\prod_{i=1}^k(1-\dfrac{1}{p_i})$ (ただし $p_i$ は $n$ の素因数)

これは各素因数側から割っていっても同じように計算できるので, $n$ 以下のテーブルを効率的に構築可能である.

* `euler_phi_table(n)`: `n` 以下のオイラーの $\phi$ 関数テーブルを返す.

## 計算量

* $O(N \log \log N)$
