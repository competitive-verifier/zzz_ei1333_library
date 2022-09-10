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
    _deprecated_at_docs: docs/divisor.md
    document_title: "Divisor(\u7D04\u6570\u5217\u6319)"
    links: []
  bundledCode: "#line 1 \"math/number-theory/divisor.hpp\"\n/**\n * @brief Divisor(\u7D04\
    \u6570\u5217\u6319)\n * @docs docs/divisor.md\n */\nvector< int64_t > divisor(int64_t\
    \ n) {\n  vector< int64_t > ret;\n  for(int64_t i = 1; i * i <= n; i++) {\n  \
    \  if(n % i == 0) {\n      ret.push_back(i);\n      if(i * i != n) ret.push_back(n\
    \ / i);\n    }\n  }\n  sort(begin(ret), end(ret));\n  return ret;\n}\n"
  code: "/**\n * @brief Divisor(\u7D04\u6570\u5217\u6319)\n * @docs docs/divisor.md\n\
    \ */\nvector< int64_t > divisor(int64_t n) {\n  vector< int64_t > ret;\n  for(int64_t\
    \ i = 1; i * i <= n; i++) {\n    if(n % i == 0) {\n      ret.push_back(i);\n \
    \     if(i * i != n) ret.push_back(n / i);\n    }\n  }\n  sort(begin(ret), end(ret));\n\
    \  return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/number-theory/divisor.hpp
  requiredBy: []
  timestamp: '2022-09-11 00:53:50+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/verify/aoj-itp1-3-d.test.cpp
documentation_of: math/number-theory/divisor.hpp
layout: document
redirect_from:
- /library/math/number-theory/divisor.hpp
- /library/math/number-theory/divisor.hpp.html
title: "Divisor(\u7D04\u6570\u5217\u6319)"
---
## 概要

ある数の約数を列挙する.

* `divisor(n)`: `n` の約数を返す.

## 計算量

* $O(\sqrt n)$
