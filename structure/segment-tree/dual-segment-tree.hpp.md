---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/verify/aoj-dsl-2-d.test.cpp
    title: test/verify/aoj-dsl-2-d.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/dual-segment-tree.md
    document_title: "Dual-Segment-Tree(\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
      )"
    links: []
  bundledCode: "#line 1 \"structure/segment-tree/dual-segment-tree.hpp\"\n/**\n *\
    \ @brief Dual-Segment-Tree(\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)\n\
    \ * @docs docs/dual-segment-tree.md\n */\ntemplate < typename E, typename H >\n\
    struct DualSegmentTree {\n  int sz, height;\n  vector< E > lazy;\n  const H h;\n\
    \  const E ei;\n\n  DualSegmentTree(int n, const H h, const E& ei): h(h), ei(ei)\
    \ {\n    sz     = 1;\n    height = 0;\n    while (sz < n) sz <<= 1, height++;\n\
    \    lazy.assign(2 * sz, ei);\n  }\n\n  inline void propagate(int k) {\n    if\
    \ (lazy[k] != ei) {\n      lazy[2 * k + 0] = h(lazy[2 * k + 0], lazy[k]);\n  \
    \    lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);\n      lazy[k]         = ei;\n\
    \    }\n  }\n\n  inline void thrust(int k) {\n    for (int i = height; i > 0;\
    \ i--) propagate(k >> i);\n  }\n\n  void update(int a, int b, const E& x) {\n\
    \    thrust(a += sz);\n    thrust(b += sz - 1);\n    for (int l = a, r = b + 1;\
    \ l < r; l >>= 1, r >>= 1) {\n      if (l & 1) lazy[l] = h(lazy[l], x), ++l;\n\
    \      if (r & 1) --r, lazy[r] = h(lazy[r], x);\n    }\n  }\n\n  E operator[](int\
    \ k) {\n    thrust(k += sz);\n    return lazy[k];\n  }\n};\n\ntemplate < typename\
    \ E, typename H >\nDualSegmentTree< E, H > get_dual_segment_tree(int N, const\
    \ H& h,\n                                              const E& ei) {\n  return\
    \ {N, h, ei};\n}\n"
  code: "/**\n * @brief Dual-Segment-Tree(\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\
    \u6728)\n * @docs docs/dual-segment-tree.md\n */\ntemplate < typename E, typename\
    \ H >\nstruct DualSegmentTree {\n  int sz, height;\n  vector< E > lazy;\n  const\
    \ H h;\n  const E ei;\n\n  DualSegmentTree(int n, const H h, const E& ei): h(h),\
    \ ei(ei) {\n    sz     = 1;\n    height = 0;\n    while (sz < n) sz <<= 1, height++;\n\
    \    lazy.assign(2 * sz, ei);\n  }\n\n  inline void propagate(int k) {\n    if\
    \ (lazy[k] != ei) {\n      lazy[2 * k + 0] = h(lazy[2 * k + 0], lazy[k]);\n  \
    \    lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);\n      lazy[k]         = ei;\n\
    \    }\n  }\n\n  inline void thrust(int k) {\n    for (int i = height; i > 0;\
    \ i--) propagate(k >> i);\n  }\n\n  void update(int a, int b, const E& x) {\n\
    \    thrust(a += sz);\n    thrust(b += sz - 1);\n    for (int l = a, r = b + 1;\
    \ l < r; l >>= 1, r >>= 1) {\n      if (l & 1) lazy[l] = h(lazy[l], x), ++l;\n\
    \      if (r & 1) --r, lazy[r] = h(lazy[r], x);\n    }\n  }\n\n  E operator[](int\
    \ k) {\n    thrust(k += sz);\n    return lazy[k];\n  }\n};\n\ntemplate < typename\
    \ E, typename H >\nDualSegmentTree< E, H > get_dual_segment_tree(int N, const\
    \ H& h,\n                                              const E& ei) {\n  return\
    \ {N, h, ei};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/segment-tree/dual-segment-tree.hpp
  requiredBy: []
  timestamp: '2022-08-27 15:55:50+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/verify/aoj-dsl-2-d.test.cpp
documentation_of: structure/segment-tree/dual-segment-tree.hpp
layout: document
redirect_from:
- /library/structure/segment-tree/dual-segment-tree.hpp
- /library/structure/segment-tree/dual-segment-tree.hpp.html
title: "Dual-Segment-Tree(\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
---
## 概要
双対セグメント木は遅延伝搬セグメント木の作用素モノイドのみを取り出したセグメント木を指す.

## 使い方

* `DualSegmentTree(n, h, OM0)`: サイズ `n` で初期化する. ここで `h` は2つの区間の作用素をマージする二項演算, `OM0` は作用素の単位元である.
* `update(l, r, x)`: 区間 $[l, r)$ に作用素 `x` を適用する.
* `operator[k]`: `k` 番目の作用素を返す.

`auto seg = get_dual_segment_tree(N, h, OM0);` のようにすると `decltype(h)` などを用いなくてすむ.

## 計算量

* クエリ: $O(\log N)$
