---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: math/number-theory/enumerate-primes.hpp
    title: "Enumerate Primes(\u7D20\u6570\u5217\u6319)"
  - icon: ':x:'
    path: math/number-theory/prime-count.hpp
    title: "Prime Count(\u7D20\u6570\u306E\u500B\u6570)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj-alds-1-1-c-2.test.cpp
    title: test/verify/aoj-alds-1-1-c-2.test.cpp
  - icon: ':x:'
    path: test/verify/yosupo-counting-primes.test.cpp
    title: test/verify/yosupo-counting-primes.test.cpp
  - icon: ':x:'
    path: test/verify/yosupo-enumerate-primes.test.cpp
    title: test/verify/yosupo-enumerate-primes.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: docs/prime-table.md
    document_title: "Prime Table(\u7D20\u6570\u30C6\u30FC\u30D6\u30EB)"
    links: []
  bundledCode: "#line 1 \"math/number-theory/prime-table.hpp\"\n/**\n * @brief Prime\
    \ Table(\u7D20\u6570\u30C6\u30FC\u30D6\u30EB)\n * @docs docs/prime-table.md\n\
    \ */\nvector< bool > prime_table(int n) {\n  vector< bool > prime(n + 1, true);\n\
    \  if(n >= 0) prime[0] = false;\n  if(n >= 1) prime[1] = false;\n  for(int i =\
    \ 2; i * i <= n; i++) {\n    if(!prime[i]) continue;\n    for(int j = i * i; j\
    \ <= n; j += i) {\n      prime[j] = false;\n    }\n  }\n  return prime;\n}\n"
  code: "/**\n * @brief Prime Table(\u7D20\u6570\u30C6\u30FC\u30D6\u30EB)\n * @docs\
    \ docs/prime-table.md\n */\nvector< bool > prime_table(int n) {\n  vector< bool\
    \ > prime(n + 1, true);\n  if(n >= 0) prime[0] = false;\n  if(n >= 1) prime[1]\
    \ = false;\n  for(int i = 2; i * i <= n; i++) {\n    if(!prime[i]) continue;\n\
    \    for(int j = i * i; j <= n; j += i) {\n      prime[j] = false;\n    }\n  }\n\
    \  return prime;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/number-theory/prime-table.hpp
  requiredBy:
  - math/number-theory/enumerate-primes.hpp
  - math/number-theory/prime-count.hpp
  timestamp: '2022-07-05 18:16:30+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/verify/yosupo-counting-primes.test.cpp
  - test/verify/yosupo-enumerate-primes.test.cpp
  - test/verify/aoj-alds-1-1-c-2.test.cpp
documentation_of: math/number-theory/prime-table.hpp
layout: document
redirect_from:
- /library/math/number-theory/prime-table.hpp
- /library/math/number-theory/prime-table.hpp.html
title: "Prime Table(\u7D20\u6570\u30C6\u30FC\u30D6\u30EB)"
---
## 概要

エラトステネスの篩により $n$ 以下の全ての値について素数かどうかを判定する.

## 使い方

* `prime_table(n)`: $n$ 以下の全ての値について素数かどうか判定するための長さ $n + 1$ の配列を返す. $i$ が素数のとき $i$ 番目の要素は `true` で, 非素数のとき `false` が格納される.

## 計算量

* $O(n \log \log n)$
