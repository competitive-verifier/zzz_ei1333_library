---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/verify/aoj-itp1-3-d.test.cpp
    title: test/verify/aoj-itp1-3-d.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/number-theory/divisor.hpp\"\nvector< int64_t > divisor(int64_t\
    \ n) {\n  vector< int64_t > ret;\n  for(int64_t i = 1; i * i <= n; i++) {\n  \
    \  if(n % i == 0) {\n      ret.push_back(i);\n      if(i * i != n) ret.push_back(n\
    \ / i);\n    }\n  }\n  sort(begin(ret), end(ret));\n  return ret;\n}\n"
  code: "vector< int64_t > divisor(int64_t n) {\n  vector< int64_t > ret;\n  for(int64_t\
    \ i = 1; i * i <= n; i++) {\n    if(n % i == 0) {\n      ret.push_back(i);\n \
    \     if(i * i != n) ret.push_back(n / i);\n    }\n  }\n  sort(begin(ret), end(ret));\n\
    \  return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/number-theory/divisor.hpp
  requiredBy: []
  timestamp: '2022-10-23 20:41:53+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/verify/aoj-itp1-3-d.test.cpp
documentation_of: math/number-theory/divisor.hpp
layout: document
redirect_from:
- /library/math/number-theory/divisor.hpp
- /library/math/number-theory/divisor.hpp.html
title: math/number-theory/divisor.hpp
---
