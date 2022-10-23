---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj-dpl-1-c.test.cpp
    title: test/verify/aoj-dpl-1-c.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"dp/knapsack.hpp\"\ntemplate< typename T, typename Compare\
    \ = greater< T > >\nvector< T > knapsack(const vector< int > &w, const vector<\
    \ T > &v, const int &W, const T &NG, const Compare &comp = Compare()) {\n  const\
    \ int N = (int) w.size();\n  vector< T > dp(W + 1, NG);\n  dp[0] = T();\n  for(int\
    \ i = 0; i < N; i++) {\n    for(int j = w[i]; j <= W; j++) {\n      if(dp[j -\
    \ w[i]] != NG) {\n        if(comp(dp[j - w[i]] + v[i], dp[j])) {\n          dp[j]\
    \ = dp[j - w[i]] + v[i];\n        }\n      }\n    }\n  }\n  return dp;\n}\n"
  code: "template< typename T, typename Compare = greater< T > >\nvector< T > knapsack(const\
    \ vector< int > &w, const vector< T > &v, const int &W, const T &NG, const Compare\
    \ &comp = Compare()) {\n  const int N = (int) w.size();\n  vector< T > dp(W +\
    \ 1, NG);\n  dp[0] = T();\n  for(int i = 0; i < N; i++) {\n    for(int j = w[i];\
    \ j <= W; j++) {\n      if(dp[j - w[i]] != NG) {\n        if(comp(dp[j - w[i]]\
    \ + v[i], dp[j])) {\n          dp[j] = dp[j - w[i]] + v[i];\n        }\n     \
    \ }\n    }\n  }\n  return dp;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: dp/knapsack.hpp
  requiredBy: []
  timestamp: '2022-09-11 00:53:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/aoj-dpl-1-c.test.cpp
documentation_of: dp/knapsack.hpp
layout: document
title: "Knapsack(\u500B\u6570\u5236\u9650\u306A\u3057\u30CA\u30C3\u30D7\u30B5\u30C3\
  \u30AF\u554F\u984C)"
---

## 概要

個数制限なしナップサック問題を次に示す.

重さ $w_i$, 価値 $v_i$ であるような $N$ 種類の品物がある. 重さの和が $W$ 以下となるように選ぶとき, 価値の最大値を求めよ.

* `knapsack(w, v, W, NG, comp)`: `W` 以下の範囲で, 各重さについて価値の最大値を求める. `NG` は到達ができない場合の値で, `comp` は比較演算子.

## 計算量

* $O(NW)$
