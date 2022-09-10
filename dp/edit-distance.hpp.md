---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/verify/aoj-dpl-1-e.test.cpp
    title: test/verify/aoj-dpl-1-e.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"dp/edit-distance.hpp\"\nint edit_distance(const string &S,\
    \ const string &T) {\n  const int N = (int) S.size(), M = (int) T.size();\n  vector<\
    \ vector< int > > dp(N + 1, vector< int >(M + 1, N + M));\n  for(int i = 0; i\
    \ <= N; i++) dp[i][0] = i;\n  for(int i = 0; i <= M; i++) dp[0][i] = i;\n  for(int\
    \ i = 1; i <= N; i++) {\n    for(int j = 1; j <= M; j++) {\n      dp[i][j] = min(dp[i][j],\
    \ dp[i - 1][j] + 1);\n      dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);\n    \
    \  dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (S[i - 1] != T[j - 1]));\n    }\n\
    \  }\n  return dp[N][M];\n}\n"
  code: "int edit_distance(const string &S, const string &T) {\n  const int N = (int)\
    \ S.size(), M = (int) T.size();\n  vector< vector< int > > dp(N + 1, vector< int\
    \ >(M + 1, N + M));\n  for(int i = 0; i <= N; i++) dp[i][0] = i;\n  for(int i\
    \ = 0; i <= M; i++) dp[0][i] = i;\n  for(int i = 1; i <= N; i++) {\n    for(int\
    \ j = 1; j <= M; j++) {\n      dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);\n \
    \     dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);\n      dp[i][j] = min(dp[i][j],\
    \ dp[i - 1][j - 1] + (S[i - 1] != T[j - 1]));\n    }\n  }\n  return dp[N][M];\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: dp/edit-distance.hpp
  requiredBy: []
  timestamp: '2022-09-11 00:53:50+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/verify/aoj-dpl-1-e.test.cpp
documentation_of: dp/edit-distance.hpp
layout: document
title: "Edit Distance(\u7DE8\u96C6\u8DDD\u96E2)"
---

## 概要

レーベルシュタイン距離とも呼ばれる. $2$ つの文字列がどの程度異なっているかを示す距離の一種である.

$1$ 文字の挿入・削除・置換によって, 一方の文字列をもう一方の文字列に変形するのに必要な手順の最小値として定義される.

* `edit_distance(S, T)`: 文字列 `S, T` の編集距離を返す.

## 計算量

* $O(nm)$
