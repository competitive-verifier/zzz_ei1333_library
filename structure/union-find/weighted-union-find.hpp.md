---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/verify/aoj-dsl-1-b.test.cpp
    title: test/verify/aoj-dsl-1-b.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"structure/union-find/weighted-union-find.hpp\"\ntemplate<\
    \ typename T >\nstruct WeightedUnionFind {\n  vector< int > data;\n  vector< T\
    \ > ws;\n\n  WeightedUnionFind() {}\n\n  WeightedUnionFind(int sz) : data(sz,\
    \ -1), ws(sz) {}\n\n  int find(int k) {\n    if(data[k] < 0) return k;\n    auto\
    \ par = find(data[k]);\n    ws[k] += ws[data[k]];\n    return data[k] = par;\n\
    \  }\n\n  T weight(int t) {\n    find(t);\n    return ws[t];\n  }\n\n  bool unite(int\
    \ x, int y, T w) {\n    w += weight(x);\n    w -= weight(y);\n    x = find(x),\
    \ y = find(y);\n    if(x == y) return false;\n    if(data[x] > data[y]) {\n  \
    \    swap(x, y);\n      w *= -1;\n    }\n    data[x] += data[y];\n    data[y]\
    \ = x;\n    ws[y] = w;\n    return true;\n  }\n\n  T diff(int x, int y) {\n  \
    \  return weight(y) - weight(x);\n  }\n};\n"
  code: "template< typename T >\nstruct WeightedUnionFind {\n  vector< int > data;\n\
    \  vector< T > ws;\n\n  WeightedUnionFind() {}\n\n  WeightedUnionFind(int sz)\
    \ : data(sz, -1), ws(sz) {}\n\n  int find(int k) {\n    if(data[k] < 0) return\
    \ k;\n    auto par = find(data[k]);\n    ws[k] += ws[data[k]];\n    return data[k]\
    \ = par;\n  }\n\n  T weight(int t) {\n    find(t);\n    return ws[t];\n  }\n\n\
    \  bool unite(int x, int y, T w) {\n    w += weight(x);\n    w -= weight(y);\n\
    \    x = find(x), y = find(y);\n    if(x == y) return false;\n    if(data[x] >\
    \ data[y]) {\n      swap(x, y);\n      w *= -1;\n    }\n    data[x] += data[y];\n\
    \    data[y] = x;\n    ws[y] = w;\n    return true;\n  }\n\n  T diff(int x, int\
    \ y) {\n    return weight(y) - weight(x);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/union-find/weighted-union-find.hpp
  requiredBy: []
  timestamp: '2022-07-05 18:16:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/verify/aoj-dsl-1-b.test.cpp
documentation_of: structure/union-find/weighted-union-find.hpp
layout: document
redirect_from:
- /library/structure/union-find/weighted-union-find.hpp
- /library/structure/union-find/weighted-union-find.hpp.html
title: structure/union-find/weighted-union-find.hpp
---
