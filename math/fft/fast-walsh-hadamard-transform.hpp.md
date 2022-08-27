---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: math/fft/bitwise-xor-convolution.hpp
    title: "Bitwise Xor Convolution (Bitwise-XOR\u7573\u307F\u8FBC\u307F)"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/verify/yosupo-bitwise-xor-convolution.test.cpp
    title: test/verify/yosupo-bitwise-xor-convolution.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "Fast Walsh Hadamard Transform (\u9AD8\u901F\u30A6\u30A9\u30EB\
      \u30B7\u30E5\u30A2\u30C0\u30DE\u30FC\u30EB\u5909\u63DB)"
    links: []
  bundledCode: "#line 1 \"math/fft/fast-walsh-hadamard-transform.hpp\"\n/**\n * @brief\
    \ Fast Walsh Hadamard Transform (\u9AD8\u901F\u30A6\u30A9\u30EB\u30B7\u30E5\u30A2\
    \u30C0\u30DE\u30FC\u30EB\u5909\u63DB)\n */\ntemplate < typename T >\nvoid fast_walsh_hadamard_transform(vector<\
    \ T > &f, bool inv = false) {\n  const int n = (int)f.size();\n  assert((n & (n\
    \ - 1)) == 0);\n  for (int i = 1; i < n; i <<= 1) {\n    for (int j = 0; j < n;\
    \ j += i << 1) {\n      for (int k = 0; k < i; k++) {\n        T s = f[j + k],\
    \ t = f[j + k + i];\n        f[j + k]     = s + t;\n        f[j + k + i] = s -\
    \ t;\n      }\n    }\n  }\n  if (inv) {\n    T inv_n = T(1) / n;\n    for (auto\
    \ &x: f) x *= inv_n;\n  }\n}\n"
  code: "/**\n * @brief Fast Walsh Hadamard Transform (\u9AD8\u901F\u30A6\u30A9\u30EB\
    \u30B7\u30E5\u30A2\u30C0\u30DE\u30FC\u30EB\u5909\u63DB)\n */\ntemplate < typename\
    \ T >\nvoid fast_walsh_hadamard_transform(vector< T > &f, bool inv = false) {\n\
    \  const int n = (int)f.size();\n  assert((n & (n - 1)) == 0);\n  for (int i =\
    \ 1; i < n; i <<= 1) {\n    for (int j = 0; j < n; j += i << 1) {\n      for (int\
    \ k = 0; k < i; k++) {\n        T s = f[j + k], t = f[j + k + i];\n        f[j\
    \ + k]     = s + t;\n        f[j + k + i] = s - t;\n      }\n    }\n  }\n  if\
    \ (inv) {\n    T inv_n = T(1) / n;\n    for (auto &x: f) x *= inv_n;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/fft/fast-walsh-hadamard-transform.hpp
  requiredBy:
  - math/fft/bitwise-xor-convolution.hpp
  timestamp: '2022-08-27 15:55:50+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/verify/yosupo-bitwise-xor-convolution.test.cpp
documentation_of: math/fft/fast-walsh-hadamard-transform.hpp
layout: document
redirect_from:
- /library/math/fft/fast-walsh-hadamard-transform.hpp
- /library/math/fft/fast-walsh-hadamard-transform.hpp.html
title: "Fast Walsh Hadamard Transform (\u9AD8\u901F\u30A6\u30A9\u30EB\u30B7\u30E5\u30A2\
  \u30C0\u30DE\u30FC\u30EB\u5909\u63DB)"
---
