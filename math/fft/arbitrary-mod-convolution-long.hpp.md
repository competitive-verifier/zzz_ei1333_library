---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/fft/arbitrary-mod-convolution-long.hpp\"\ntemplate<\
    \ typename T >\nstruct ArbitraryModConvolutionLong {\n  using real = FastFourierTransform::real;\n\
    \  using C = FastFourierTransform::C;\n \n  ArbitraryModConvolutionLong() = default;\n\
    \ \n  vector< T > multiply(const vector< T > &a, const vector< T > &b, int need\
    \ = -1) {\n    if(need == -1) need = a.size() + b.size() - 1;\n    int nbase =\
    \ 0;\n    while((1 << nbase) < need) nbase++;\n    FastFourierTransform::ensure_base(nbase);\n\
    \    int sz = 1 << nbase;\n    vector< C > fa(sz);\n    for(int i = 0; i < a.size();\
    \ i++) {\n      fa[i] = C(a[i].x & ((1 << 19) - 1), a[i].x >> 19);\n    }\n  \
    \  fft(fa, sz);\n    vector< C > fb(sz);\n    if(a == b) {\n      fb = fa;\n \
    \   } else {\n      for(int i = 0; i < b.size(); i++) {\n        fb[i] = C(b[i].x\
    \ & ((1 << 19) - 1), b[i].x >> 19);\n      }\n      fft(fb, sz);\n    }\n    real\
    \ ratio = 0.25 / sz;\n    C r2(0, -1), r3(ratio, 0), r4(0, -ratio), r5(0, 1);\n\
    \    for(int i = 0; i <= (sz >> 1); i++) {\n      int j = (sz - i) & (sz - 1);\n\
    \      C a1 = (fa[i] + fa[j].conj());\n      C a2 = (fa[i] - fa[j].conj()) * r2;\n\
    \      C b1 = (fb[i] + fb[j].conj()) * r3;\n      C b2 = (fb[i] - fb[j].conj())\
    \ * r4;\n      if(i != j) {\n        C c1 = (fa[j] + fa[i].conj());\n        C\
    \ c2 = (fa[j] - fa[i].conj()) * r2;\n        C d1 = (fb[j] + fb[i].conj()) * r3;\n\
    \        C d2 = (fb[j] - fb[i].conj()) * r4;\n        fa[i] = c1 * d1 + c2 * d2\
    \ * r5;\n        fb[i] = c1 * d2 + c2 * d1;\n      }\n      fa[j] = a1 * b1 +\
    \ a2 * b2 * r5;\n      fb[j] = a1 * b2 + a2 * b1;\n    }\n    fft(fa, sz);\n \
    \   fft(fb, sz);\n    vector< T > ret(need);\n    auto mul1 = T(2).pow(19);\n\
    \    auto mul2 = T(2).pow(38);\n    for(int i = 0; i < need; i++) {\n      int64_t\
    \ aa = llround(fa[i].x);\n      int64_t bb = llround(fb[i].x);\n      int64_t\
    \ cc = llround(fa[i].y);\n      aa = T(aa).x, bb = T(bb).x, cc = T(cc).x;\n  \
    \    ret[i] = (mul1 * bb) + (mul2 * cc) + aa;\n    }\n    return ret;\n  }\n};\n"
  code: "template< typename T >\nstruct ArbitraryModConvolutionLong {\n  using real\
    \ = FastFourierTransform::real;\n  using C = FastFourierTransform::C;\n \n  ArbitraryModConvolutionLong()\
    \ = default;\n \n  vector< T > multiply(const vector< T > &a, const vector< T\
    \ > &b, int need = -1) {\n    if(need == -1) need = a.size() + b.size() - 1;\n\
    \    int nbase = 0;\n    while((1 << nbase) < need) nbase++;\n    FastFourierTransform::ensure_base(nbase);\n\
    \    int sz = 1 << nbase;\n    vector< C > fa(sz);\n    for(int i = 0; i < a.size();\
    \ i++) {\n      fa[i] = C(a[i].x & ((1 << 19) - 1), a[i].x >> 19);\n    }\n  \
    \  fft(fa, sz);\n    vector< C > fb(sz);\n    if(a == b) {\n      fb = fa;\n \
    \   } else {\n      for(int i = 0; i < b.size(); i++) {\n        fb[i] = C(b[i].x\
    \ & ((1 << 19) - 1), b[i].x >> 19);\n      }\n      fft(fb, sz);\n    }\n    real\
    \ ratio = 0.25 / sz;\n    C r2(0, -1), r3(ratio, 0), r4(0, -ratio), r5(0, 1);\n\
    \    for(int i = 0; i <= (sz >> 1); i++) {\n      int j = (sz - i) & (sz - 1);\n\
    \      C a1 = (fa[i] + fa[j].conj());\n      C a2 = (fa[i] - fa[j].conj()) * r2;\n\
    \      C b1 = (fb[i] + fb[j].conj()) * r3;\n      C b2 = (fb[i] - fb[j].conj())\
    \ * r4;\n      if(i != j) {\n        C c1 = (fa[j] + fa[i].conj());\n        C\
    \ c2 = (fa[j] - fa[i].conj()) * r2;\n        C d1 = (fb[j] + fb[i].conj()) * r3;\n\
    \        C d2 = (fb[j] - fb[i].conj()) * r4;\n        fa[i] = c1 * d1 + c2 * d2\
    \ * r5;\n        fb[i] = c1 * d2 + c2 * d1;\n      }\n      fa[j] = a1 * b1 +\
    \ a2 * b2 * r5;\n      fb[j] = a1 * b2 + a2 * b1;\n    }\n    fft(fa, sz);\n \
    \   fft(fb, sz);\n    vector< T > ret(need);\n    auto mul1 = T(2).pow(19);\n\
    \    auto mul2 = T(2).pow(38);\n    for(int i = 0; i < need; i++) {\n      int64_t\
    \ aa = llround(fa[i].x);\n      int64_t bb = llround(fb[i].x);\n      int64_t\
    \ cc = llround(fa[i].y);\n      aa = T(aa).x, bb = T(bb).x, cc = T(cc).x;\n  \
    \    ret[i] = (mul1 * bb) + (mul2 * cc) + aa;\n    }\n    return ret;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/fft/arbitrary-mod-convolution-long.hpp
  requiredBy: []
  timestamp: '2022-09-11 00:53:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/fft/arbitrary-mod-convolution-long.hpp
layout: document
redirect_from:
- /library/math/fft/arbitrary-mod-convolution-long.hpp
- /library/math/fft/arbitrary-mod-convolution-long.hpp.html
title: math/fft/arbitrary-mod-convolution-long.hpp
---
