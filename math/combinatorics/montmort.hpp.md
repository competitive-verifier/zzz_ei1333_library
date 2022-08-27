---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/verify/yosupo-montmort-number-mod.test.cpp
    title: test/verify/yosupo-montmort-number-mod.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/montmort.md
    document_title: "Montmort-Number(\u30E2\u30F3\u30E2\u30FC\u30EB\u6570)"
    links: []
  bundledCode: "#line 1 \"math/combinatorics/montmort.hpp\"\n/**\n * @brief Montmort-Number(\u30E2\
    \u30F3\u30E2\u30FC\u30EB\u6570)\n * @docs docs/montmort.md\n */\ntemplate < typename\
    \ T >\nvector< T > montmort(int N) {\n  vector< T > dp(N + 1);\n  for (int k =\
    \ 2; k <= N; k++) {\n    dp[k] = dp[k - 1] * k;\n    if (k & 1)\n      dp[k] -=\
    \ 1;\n    else\n      dp[k] += 1;\n  }\n  return dp;\n}\n"
  code: "/**\n * @brief Montmort-Number(\u30E2\u30F3\u30E2\u30FC\u30EB\u6570)\n *\
    \ @docs docs/montmort.md\n */\ntemplate < typename T >\nvector< T > montmort(int\
    \ N) {\n  vector< T > dp(N + 1);\n  for (int k = 2; k <= N; k++) {\n    dp[k]\
    \ = dp[k - 1] * k;\n    if (k & 1)\n      dp[k] -= 1;\n    else\n      dp[k] +=\
    \ 1;\n  }\n  return dp;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/combinatorics/montmort.hpp
  requiredBy: []
  timestamp: '2022-08-27 15:55:50+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/verify/yosupo-montmort-number-mod.test.cpp
documentation_of: math/combinatorics/montmort.hpp
layout: document
redirect_from:
- /library/math/combinatorics/montmort.hpp
- /library/math/combinatorics/montmort.hpp.html
title: "Montmort-Number(\u30E2\u30F3\u30E2\u30FC\u30EB\u6570)"
---
## 概要

完全順列の総数をモンモール数とよぶ.

長さ $n$ の完全順列とは, 長さ $n$ の順列であって $i(1 \leq i \leq N)$ 番目の要素が $i$ でない順列を指す.

* `montmort(n)`: `n` 番目のモンモール数を返す.

## 計算量

* $O(n)$
