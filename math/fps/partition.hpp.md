---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-partition-function.test.cpp
    title: test/verify/yosupo-partition-function.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Partition(\u5206\u5272\u6570)"
    links: []
  bundledCode: "#line 1 \"math/fps/partition.hpp\"\n/**\n * @brief Partition(\u5206\
    \u5272\u6570)\n */\ntemplate< template< typename > class FPS, typename Mint >\n\
    FPS< Mint > partition(int N) {\n  FPS< Mint > poly(N + 1);\n  poly[0] = 1;\n \
    \ for(int k = 1; k <= N; k++) {\n    if(1LL * k * (3 * k + 1) / 2 <= N) poly[k\
    \ * (3 * k + 1) / 2] += (k % 2 ? -1 : 1);\n    if(1LL * k * (3 * k - 1) / 2 <=\
    \ N) poly[k * (3 * k - 1) / 2] += (k % 2 ? -1 : 1);\n  }\n  return poly.inv();\n\
    }\n"
  code: "/**\n * @brief Partition(\u5206\u5272\u6570)\n */\ntemplate< template< typename\
    \ > class FPS, typename Mint >\nFPS< Mint > partition(int N) {\n  FPS< Mint >\
    \ poly(N + 1);\n  poly[0] = 1;\n  for(int k = 1; k <= N; k++) {\n    if(1LL *\
    \ k * (3 * k + 1) / 2 <= N) poly[k * (3 * k + 1) / 2] += (k % 2 ? -1 : 1);\n \
    \   if(1LL * k * (3 * k - 1) / 2 <= N) poly[k * (3 * k - 1) / 2] += (k % 2 ? -1\
    \ : 1);\n  }\n  return poly.inv();\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/fps/partition.hpp
  requiredBy: []
  timestamp: '2022-07-05 18:16:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/yosupo-partition-function.test.cpp
documentation_of: math/fps/partition.hpp
layout: document
redirect_from:
- /library/math/fps/partition.hpp
- /library/math/fps/partition.hpp.html
title: "Partition(\u5206\u5272\u6570)"
---
