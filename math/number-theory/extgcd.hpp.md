---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj-ntl-1-e.test.cpp
    title: test/verify/aoj-ntl-1-e.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/number-theory/extgcd.hpp\"\ntemplate< typename T >\n\
    T extgcd(T a, T b, T &x, T &y) {\n  T d = a;\n  if(b != 0) {\n    d = extgcd(b,\
    \ a % b, y, x);\n    y -= (a / b) * x;\n  } else {\n    x = 1;\n    y = 0;\n \
    \ }\n  return d;\n}\n"
  code: "template< typename T >\nT extgcd(T a, T b, T &x, T &y) {\n  T d = a;\n  if(b\
    \ != 0) {\n    d = extgcd(b, a % b, y, x);\n    y -= (a / b) * x;\n  } else {\n\
    \    x = 1;\n    y = 0;\n  }\n  return d;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/number-theory/extgcd.hpp
  requiredBy: []
  timestamp: '2022-10-23 21:27:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/aoj-ntl-1-e.test.cpp
documentation_of: math/number-theory/extgcd.hpp
layout: document
title: "Extgcd(\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5\
  )"
---

# extgcd

```
T extgcd(T a, T b, T &x, T &y)
```

$\gcd(a, b)$ を返します。$(x, y)$ には $ax + by = \gcd(a, b)$ を満たす整数解が格納されます。整数解は複数考えられるが, $\|x\| + \|y\|$ が最小のものが格納されます。

## 制約

- $1 \leq a, b$

## 計算量

- $O(\log {\min(a, b)})$
