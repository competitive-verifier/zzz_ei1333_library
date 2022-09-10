---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj-0560.test.cpp
    title: test/verify/aoj-0560.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"dp/cumulative-sum-2d.hpp\"\ntemplate< class T >\nstruct\
    \ CumulativeSum2D {\n  vector< vector< T > > data;\n\n  CumulativeSum2D(int W,\
    \ int H) : data(W + 1, vector< T >(H + 1, 0)) {}\n\n  void add(int x, int y, T\
    \ z) {\n    ++x, ++y;\n    if(x >= data.size() || y >= data[0].size()) return;\n\
    \    data[x][y] += z;\n  }\n\n  void build() {\n    for(int i = 1; i < data.size();\
    \ i++) {\n      for(int j = 1; j < data[i].size(); j++) {\n        data[i][j]\
    \ += data[i][j - 1] + data[i - 1][j] - data[i - 1][j - 1];\n      }\n    }\n \
    \ }\n\n  T query(int sx, int sy, int gx, int gy) const {\n    return (data[gx][gy]\
    \ - data[sx][gy] - data[gx][sy] + data[sx][sy]);\n  }\n};\n"
  code: "template< class T >\nstruct CumulativeSum2D {\n  vector< vector< T > > data;\n\
    \n  CumulativeSum2D(int W, int H) : data(W + 1, vector< T >(H + 1, 0)) {}\n\n\
    \  void add(int x, int y, T z) {\n    ++x, ++y;\n    if(x >= data.size() || y\
    \ >= data[0].size()) return;\n    data[x][y] += z;\n  }\n\n  void build() {\n\
    \    for(int i = 1; i < data.size(); i++) {\n      for(int j = 1; j < data[i].size();\
    \ j++) {\n        data[i][j] += data[i][j - 1] + data[i - 1][j] - data[i - 1][j\
    \ - 1];\n      }\n    }\n  }\n\n  T query(int sx, int sy, int gx, int gy) const\
    \ {\n    return (data[gx][gy] - data[sx][gy] - data[gx][sy] + data[sx][sy]);\n\
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: dp/cumulative-sum-2d.hpp
  requiredBy: []
  timestamp: '2022-09-11 00:53:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/aoj-0560.test.cpp
documentation_of: dp/cumulative-sum-2d.hpp
layout: document
title: "Cumulative Sum 2D(\u4E8C\u6B21\u5143\u7D2F\u7A4D\u548C)"
---

## 概要

$2$ 次元の累積和. 前計算として事前に累積和をとることで, 矩形和を $O(1)$ で求めることが出来る.

* `add(x, y, z)`: 要素 $(x, y)$ に値 `z` を加える.
* `build()`: 累積和を構築する.
* `query(sx, sy, gx, gy)`: 左下 $(sx, sy)$, 右上 $(gx, gy)$ の矩形和を求める(半開区間で与えることに注意すること. 具体的には列 $gx$ と行 $gy$ は含まない).

## 計算量

* `add(x, y, z)`: $O(1)$
* `build()`: $O(WH)$
* `query(sx, sy, gx, gy)`: $O(1)$
