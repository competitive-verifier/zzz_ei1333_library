---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/number-theory/prime-table.hpp
    title: "Prime Table(\u7D20\u6570\u30C6\u30FC\u30D6\u30EB)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/verify/yosupo-enumerate-primes.test.cpp
    title: test/verify/yosupo-enumerate-primes.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/number-theory/prime-table.hpp\"\n/**\n * @brief Prime\
    \ Table(\u7D20\u6570\u30C6\u30FC\u30D6\u30EB)\n * @docs docs/prime-table.md\n\
    \ */\nvector< bool > prime_table(int n) {\n  vector< bool > prime(n + 1, true);\n\
    \  if(n >= 0) prime[0] = false;\n  if(n >= 1) prime[1] = false;\n  for(int i =\
    \ 2; i * i <= n; i++) {\n    if(!prime[i]) continue;\n    for(int j = i * i; j\
    \ <= n; j += i) {\n      prime[j] = false;\n    }\n  }\n  return prime;\n}\n#line\
    \ 2 \"math/number-theory/enumerate-primes.hpp\"\n\nvector< int > enumerate_primes(int\
    \ n) {\n  if(n <= 1) return {};\n  auto d = prime_table(n);\n  vector< int > primes;\n\
    \  primes.reserve(count(begin(d), end(d), true));\n  for(int i = 0; i < d.size();\
    \ i++) {\n    if(d[i]) primes.push_back(i);\n  }\n  return primes;\n}\n"
  code: "#include \"prime-table.hpp\"\n\nvector< int > enumerate_primes(int n) {\n\
    \  if(n <= 1) return {};\n  auto d = prime_table(n);\n  vector< int > primes;\n\
    \  primes.reserve(count(begin(d), end(d), true));\n  for(int i = 0; i < d.size();\
    \ i++) {\n    if(d[i]) primes.push_back(i);\n  }\n  return primes;\n}\n"
  dependsOn:
  - math/number-theory/prime-table.hpp
  isVerificationFile: false
  path: math/number-theory/enumerate-primes.hpp
  requiredBy: []
  timestamp: '2022-10-23 20:41:53+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/verify/yosupo-enumerate-primes.test.cpp
documentation_of: math/number-theory/enumerate-primes.hpp
layout: document
title: "Enumerate Primes(\u7D20\u6570\u5217\u6319)"
---

エラトステネスの篩を用いて素数を列挙します。


# enumerate_primes

```
vector< int > enumerate_primes(int n)
```

$n$ 以下の素数を昇順に返します。

## 制約

- $0 \le n$

## 計算量

- $O(n \log \log n)$
