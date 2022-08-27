---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/verify/yosupo-bernoulli-number.test.cpp
    title: test/verify/yosupo-bernoulli-number.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "Bernoulli(\u30D9\u30EB\u30CC\u30FC\u30A4\u6570)"
    links: []
  bundledCode: "#line 1 \"math/fps/bernoulli.hpp\"\n/**\n * @brief Bernoulli(\u30D9\
    \u30EB\u30CC\u30FC\u30A4\u6570)\n */\ntemplate < template < typename > class FPS,\
    \ typename Mint >\nFPS< Mint > bernoulli(int N) {\n  FPS< Mint > poly(N + 1);\n\
    \  poly[0] = Mint(1);\n  for (int i = 1; i <= N; i++) {\n    poly[i] = poly[i\
    \ - 1] / Mint(i + 1);\n  }\n  poly = poly.inv();\n  Mint tmp(1);\n  for (int i\
    \ = 1; i <= N; i++) {\n    tmp *= Mint(i);\n    poly[i] *= tmp;\n  }\n  return\
    \ poly;\n}\n"
  code: "/**\n * @brief Bernoulli(\u30D9\u30EB\u30CC\u30FC\u30A4\u6570)\n */\ntemplate\
    \ < template < typename > class FPS, typename Mint >\nFPS< Mint > bernoulli(int\
    \ N) {\n  FPS< Mint > poly(N + 1);\n  poly[0] = Mint(1);\n  for (int i = 1; i\
    \ <= N; i++) {\n    poly[i] = poly[i - 1] / Mint(i + 1);\n  }\n  poly = poly.inv();\n\
    \  Mint tmp(1);\n  for (int i = 1; i <= N; i++) {\n    tmp *= Mint(i);\n    poly[i]\
    \ *= tmp;\n  }\n  return poly;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/fps/bernoulli.hpp
  requiredBy: []
  timestamp: '2022-08-27 15:55:50+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/verify/yosupo-bernoulli-number.test.cpp
documentation_of: math/fps/bernoulli.hpp
layout: document
redirect_from:
- /library/math/fps/bernoulli.hpp
- /library/math/fps/bernoulli.hpp.html
title: "Bernoulli(\u30D9\u30EB\u30CC\u30FC\u30A4\u6570)"
---
