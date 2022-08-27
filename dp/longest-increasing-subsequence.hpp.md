---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/verify/aoj-dpl-1-d.test.cpp
    title: test/verify/aoj-dpl-1-d.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"dp/longest-increasing-subsequence.hpp\"\ntemplate < typename\
    \ T >\nsize_t longest_increasing_subsequence(const vector< T > &a,\n         \
    \                             bool strict) {\n  vector< T > lis;\n  for (auto\
    \ &p: a) {\n    typename vector< T >::iterator it;\n    if (strict)\n      it\
    \ = lower_bound(begin(lis), end(lis), p);\n    else\n      it = upper_bound(begin(lis),\
    \ end(lis), p);\n    if (end(lis) == it)\n      lis.emplace_back(p);\n    else\n\
    \      *it = p;\n  }\n  return lis.size();\n}\n"
  code: "template < typename T >\nsize_t longest_increasing_subsequence(const vector<\
    \ T > &a,\n                                      bool strict) {\n  vector< T >\
    \ lis;\n  for (auto &p: a) {\n    typename vector< T >::iterator it;\n    if (strict)\n\
    \      it = lower_bound(begin(lis), end(lis), p);\n    else\n      it = upper_bound(begin(lis),\
    \ end(lis), p);\n    if (end(lis) == it)\n      lis.emplace_back(p);\n    else\n\
    \      *it = p;\n  }\n  return lis.size();\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: dp/longest-increasing-subsequence.hpp
  requiredBy: []
  timestamp: '2022-08-27 15:55:50+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/verify/aoj-dpl-1-d.test.cpp
documentation_of: dp/longest-increasing-subsequence.hpp
layout: document
title: "Longest Increasing Subsequence(\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217)"
---

## 概要

最長増加部分列(LIS)の長さを求める.

`lis[i]` を、現状態で長さ $i$ 以下の増加部分列を作るときの最後の要素の最小値と定義する. このとき `lis[i]` は常に単調増加になっている.

数列の要素を左からみる. 二分探索で `lis[k]` が現在の要素以下(未満) となる最大の $k$ を求め, `lis[k+1]` を現在の要素に書き換えることを繰り返すことで LIS を求めることができる.

ここでは実装しない(←実装しなさーい！)が別のアルゴリズムとして, `lis[i]` を現状態で最後の要素が値 $i$ の増加部分列を作るときの最長の長さと定義する方法も存在する. 数列の要素を左から見ていって, 現在の値の要素以下(未満) で最大の `lis[k]` $+ 1$ を求めることで更新出来て, これは BIT や セグメント木を使って効率的に求めることができる.

* `longest_increasing_subsequence(a, strict)`: 数列 `a` の最長増加部分列の長さを求める.`strict` が `true` のとき狭義(厳密に増加する列), `false` のとき広義で求める.

## 計算量

* $O(N \log N)$
