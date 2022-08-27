---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: math/fft/bitwise-or-convolution.hpp
    title: "Bitwise Or Convolution (Bitwise-OR\u7573\u307F\u8FBC\u307F)"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/verify/yosupo-bitwise-and-convolution-2.test.cpp
    title: test/verify/yosupo-bitwise-and-convolution-2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "Subset Zeta/Moebius Transform (\u4E0B\u4F4D\u96C6\u5408\u306E\
      \u30BC\u30FC\u30BF/\u30E1\u30D3\u30A6\u30B9\u5909\u63DB)"
    links: []
  bundledCode: "#line 1 \"math/fft/subset-zeta-moebius-transform.hpp\"\n/**\n * @brief\
    \ Subset Zeta/Moebius Transform (\u4E0B\u4F4D\u96C6\u5408\u306E\u30BC\u30FC\u30BF\
    /\u30E1\u30D3\u30A6\u30B9\u5909\u63DB)\n */\ntemplate < typename T >\nvoid subset_zeta_transform(vector<\
    \ T > &f) {\n  const int n = (int)f.size();\n  assert((n & (n - 1)) == 0);\n \
    \ for (int i = 1; i < n; i <<= 1) {\n    for (int j = 0; j < n; j += i << 1) {\n\
    \      for (int k = 0; k < i; k++) {\n        f[j + k + i] += f[j + k];\n    \
    \  }\n    }\n  }\n}\n\ntemplate < typename T >\nvoid subset_moebius_transform(vector<\
    \ T > &f) {\n  const int n = (int)f.size();\n  assert((n & (n - 1)) == 0);\n \
    \ for (int i = 1; i < n; i <<= 1) {\n    for (int j = 0; j < n; j += i << 1) {\n\
    \      for (int k = 0; k < i; k++) {\n        f[j + k + i] -= f[j + k];\n    \
    \  }\n    }\n  }\n}\n"
  code: "/**\n * @brief Subset Zeta/Moebius Transform (\u4E0B\u4F4D\u96C6\u5408\u306E\
    \u30BC\u30FC\u30BF/\u30E1\u30D3\u30A6\u30B9\u5909\u63DB)\n */\ntemplate < typename\
    \ T >\nvoid subset_zeta_transform(vector< T > &f) {\n  const int n = (int)f.size();\n\
    \  assert((n & (n - 1)) == 0);\n  for (int i = 1; i < n; i <<= 1) {\n    for (int\
    \ j = 0; j < n; j += i << 1) {\n      for (int k = 0; k < i; k++) {\n        f[j\
    \ + k + i] += f[j + k];\n      }\n    }\n  }\n}\n\ntemplate < typename T >\nvoid\
    \ subset_moebius_transform(vector< T > &f) {\n  const int n = (int)f.size();\n\
    \  assert((n & (n - 1)) == 0);\n  for (int i = 1; i < n; i <<= 1) {\n    for (int\
    \ j = 0; j < n; j += i << 1) {\n      for (int k = 0; k < i; k++) {\n        f[j\
    \ + k + i] -= f[j + k];\n      }\n    }\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/fft/subset-zeta-moebius-transform.hpp
  requiredBy:
  - math/fft/bitwise-or-convolution.hpp
  timestamp: '2022-08-27 15:55:50+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/verify/yosupo-bitwise-and-convolution-2.test.cpp
documentation_of: math/fft/subset-zeta-moebius-transform.hpp
layout: document
redirect_from:
- /library/math/fft/subset-zeta-moebius-transform.hpp
- /library/math/fft/subset-zeta-moebius-transform.hpp.html
title: "Subset Zeta/Moebius Transform (\u4E0B\u4F4D\u96C6\u5408\u306E\u30BC\u30FC\u30BF\
  /\u30E1\u30D3\u30A6\u30B9\u5909\u63DB)"
---
