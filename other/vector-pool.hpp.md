---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj-1508-2.test.cpp
    title: test/verify/aoj-1508-2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj-1508-3.test.cpp
    title: test/verify/aoj-1508-3.test.cpp
  - icon: ':x:'
    path: test/verify/yosupo-range-affine-range-sum-2.test.cpp
    title: test/verify/yosupo-range-affine-range-sum-2.test.cpp
  - icon: ':x:'
    path: test/verify/yosupo-range-affine-range-sum-3.test.cpp
    title: test/verify/yosupo-range-affine-range-sum-3.test.cpp
  - icon: ':x:'
    path: test/verify/yosupo-staticrmq-3.test.cpp
    title: test/verify/yosupo-staticrmq-3.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"other/vector-pool.hpp\"\ntemplate< class T >\nstruct VectorPool\
    \ {\n  vector< T > pool;\n  vector< T * > stock;\n  int ptr;\n\n  VectorPool()\
    \ = default;\n\n  VectorPool(int sz) : pool(sz), stock(sz) {}\n\n  inline T *alloc()\
    \ { return stock[--ptr]; }\n\n  inline void free(T *t) { stock[ptr++] = t; }\n\
    \n  void clear() {\n    ptr = (int) pool.size();\n    for(int i = 0; i < pool.size();\
    \ i++) stock[i] = &pool[i];\n  }\n};\n"
  code: "template< class T >\nstruct VectorPool {\n  vector< T > pool;\n  vector<\
    \ T * > stock;\n  int ptr;\n\n  VectorPool() = default;\n\n  VectorPool(int sz)\
    \ : pool(sz), stock(sz) {}\n\n  inline T *alloc() { return stock[--ptr]; }\n\n\
    \  inline void free(T *t) { stock[ptr++] = t; }\n\n  void clear() {\n    ptr =\
    \ (int) pool.size();\n    for(int i = 0; i < pool.size(); i++) stock[i] = &pool[i];\n\
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: other/vector-pool.hpp
  requiredBy: []
  timestamp: '2022-07-05 18:16:30+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/verify/aoj-1508-2.test.cpp
  - test/verify/yosupo-range-affine-range-sum-2.test.cpp
  - test/verify/yosupo-staticrmq-3.test.cpp
  - test/verify/yosupo-range-affine-range-sum-3.test.cpp
  - test/verify/aoj-1508-3.test.cpp
documentation_of: other/vector-pool.hpp
layout: document
redirect_from:
- /library/other/vector-pool.hpp
- /library/other/vector-pool.hpp.html
title: other/vector-pool.hpp
---
