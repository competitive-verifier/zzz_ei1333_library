---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj-0233.test.cpp
    title: test/verify/aoj-0233.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/number-theory/convert-base.hpp\"\ntemplate< typename\
    \ T >\nvector< T > convert_base(T x, T b) {\n  vector< T > ret;\n  T t = 1, k\
    \ = abs(b);\n  while(x) {\n    ret.emplace_back((x * t) % k);\n    if(ret.back()\
    \ < 0) ret.back() += k;\n    x -= ret.back() * t;\n    x /= k;\n    t *= b / k;\n\
    \  }\n  if(ret.empty()) ret.emplace_back(0);\n  reverse(begin(ret), end(ret));\n\
    \  return ret;\n}\n"
  code: "template< typename T >\nvector< T > convert_base(T x, T b) {\n  vector< T\
    \ > ret;\n  T t = 1, k = abs(b);\n  while(x) {\n    ret.emplace_back((x * t) %\
    \ k);\n    if(ret.back() < 0) ret.back() += k;\n    x -= ret.back() * t;\n   \
    \ x /= k;\n    t *= b / k;\n  }\n  if(ret.empty()) ret.emplace_back(0);\n  reverse(begin(ret),\
    \ end(ret));\n  return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/number-theory/convert-base.hpp
  requiredBy: []
  timestamp: '2022-10-23 20:41:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/aoj-0233.test.cpp
documentation_of: math/number-theory/convert-base.hpp
layout: document
redirect_from:
- /library/math/number-theory/convert-base.hpp
- /library/math/number-theory/convert-base.hpp.html
title: math/number-theory/convert-base.hpp
---
