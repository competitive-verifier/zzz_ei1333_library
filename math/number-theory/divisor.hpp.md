---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj-itp1-3-d.test.cpp
    title: test/verify/aoj-itp1-3-d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/aoj-itp1-3-d.test.cpp
documentation_of: math/number-theory/divisor.hpp
layout: document
title: "Divisor(\u7D04\u6570\u5217\u6319)"
---

与えられた整数の約数を列挙します。

# divisor

```
vector< int64_t > divisor(int64_t n)
```

`n` の約数を昇順に返します。

## 制約

- $1 \le n$

## 計算量

- $O(\sqrt n)$
