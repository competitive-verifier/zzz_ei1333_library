---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/quotient-ranges.md
    document_title: "Quotient Ranges(\u5546\u5217\u6319)"
    links: []
  bundledCode: "#line 1 \"math/number-theory/quotient-ranges.hpp\"\n/**\n * @brief\
    \ Quotient Ranges(\u5546\u5217\u6319)\n * @docs docs/quotient-ranges.md\n */\n\
    template< typename T >\nvector< pair< pair< T, T >, T > > quotient_ranges(T N)\
    \ {\n  vector< pair< pair< T, T >, T > > ret;\n  T l = 1;\n  while(l <= N) {\n\
    \    T q = N / l;\n    T r = N / q + 1;\n    ret.emplace_back(make_pair(l, r),\
    \ q);\n    l = r;\n  }\n  return ret;\n}\n"
  code: "/**\n * @brief Quotient Ranges(\u5546\u5217\u6319)\n * @docs docs/quotient-ranges.md\n\
    \ */\ntemplate< typename T >\nvector< pair< pair< T, T >, T > > quotient_ranges(T\
    \ N) {\n  vector< pair< pair< T, T >, T > > ret;\n  T l = 1;\n  while(l <= N)\
    \ {\n    T q = N / l;\n    T r = N / q + 1;\n    ret.emplace_back(make_pair(l,\
    \ r), q);\n    l = r;\n  }\n  return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/number-theory/quotient-ranges.hpp
  requiredBy: []
  timestamp: '2022-09-11 00:53:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/number-theory/quotient-ranges.hpp
layout: document
redirect_from:
- /library/math/number-theory/quotient-ranges.hpp
- /library/math/number-theory/quotient-ranges.hpp.html
title: "Quotient Ranges(\u5546\u5217\u6319)"
---
## 概要

整数 $N$ が与えられたとき, $N$ の商 ($\lfloor \frac N i \rfloor$) ($1 \leq i \leq N$) の値と対応する区間を列挙する.

## 使い方

* `quotient_ranges(N)`: 戻り値の各要素を \{\{$x$,$y$\},$z$\} とする。$x \leq i \lt y$ を満たす整数の商($\lfloor \frac N i \rfloor$) が $z$ であることを意味する。$x$ の昇順で返す.

## 計算量

* $O(\sqrt N)$
