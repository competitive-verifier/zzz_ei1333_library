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
  bundledCode: "#line 1 \"other/random-number-generator.hpp\"\nstruct RandomNumberGenerator\
    \ {\n  mt19937 mt;\n\n  RandomNumberGenerator()\n      : mt(chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n\n  int operator()(int a, int b) { // [a, b)\n    uniform_int_distribution<\
    \ int > dist(a, b - 1);\n    return dist(mt);\n  }\n\n  int operator()(int b)\
    \ { // [0, b)\n    return (*this)(0, b);\n  }\n};\n"
  code: "struct RandomNumberGenerator {\n  mt19937 mt;\n\n  RandomNumberGenerator()\n\
    \      : mt(chrono::steady_clock::now().time_since_epoch().count()) {}\n\n  int\
    \ operator()(int a, int b) { // [a, b)\n    uniform_int_distribution< int > dist(a,\
    \ b - 1);\n    return dist(mt);\n  }\n\n  int operator()(int b) { // [0, b)\n\
    \    return (*this)(0, b);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: other/random-number-generator.hpp
  requiredBy: []
  timestamp: '2022-08-27 15:55:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/random-number-generator.hpp
layout: document
redirect_from:
- /library/other/random-number-generator.hpp
- /library/other/random-number-generator.hpp.html
title: other/random-number-generator.hpp
---
