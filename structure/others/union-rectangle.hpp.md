---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"structure/others/union-rectangle.hpp\"\ntemplate< typename\
    \ T >\nstruct UnionRectangle {\n  map< T, T > data;\n  int64 sum;\n\n  UnionRectangle()\
    \ : sum(0) {\n    const T INF = numeric_limits< T >::max();\n    data[0] = INF;\n\
    \    data[INF] = 0;\n  }\n  void add_point(T x, T y) {\n    auto p = data.lower_bound(x);\n\
    \    if(p->second >= y) return;\n    const T nxtY = p->second;\n    --p;\n   \
    \ while(p->second <= y) {\n      auto it = *p;\n      p = --data.erase(p);\n \
    \     sum -= (it.first - p->first) * (it.second - nxtY);\n    }\n    sum += (x\
    \ - p->first) * (y - nxtY);\n    data[x] = y;\n  }\n\n  int64 get() {\n    return\
    \ sum;\n  }\n};\n"
  code: "template< typename T >\nstruct UnionRectangle {\n  map< T, T > data;\n  int64\
    \ sum;\n\n  UnionRectangle() : sum(0) {\n    const T INF = numeric_limits< T >::max();\n\
    \    data[0] = INF;\n    data[INF] = 0;\n  }\n  void add_point(T x, T y) {\n \
    \   auto p = data.lower_bound(x);\n    if(p->second >= y) return;\n    const T\
    \ nxtY = p->second;\n    --p;\n    while(p->second <= y) {\n      auto it = *p;\n\
    \      p = --data.erase(p);\n      sum -= (it.first - p->first) * (it.second -\
    \ nxtY);\n    }\n    sum += (x - p->first) * (y - nxtY);\n    data[x] = y;\n \
    \ }\n\n  int64 get() {\n    return sum;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/others/union-rectangle.hpp
  requiredBy: []
  timestamp: '2022-09-11 00:53:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/others/union-rectangle.hpp
layout: document
redirect_from:
- /library/structure/others/union-rectangle.hpp
- /library/structure/others/union-rectangle.hpp.html
title: structure/others/union-rectangle.hpp
---
