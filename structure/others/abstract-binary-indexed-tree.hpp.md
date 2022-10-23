---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: structure/others/abstract-2d-binary-indexed-tree-compressed.hpp
    title: "Abstract 2D Binary Indexed Tree Compressed(\u62BD\u8C61\u53162\u6B21\u5143\
      \u5EA7\u5727BIT)"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/verify/yosupo-point-add-rectangle-sum-2.test.cpp
    title: test/verify/yosupo-point-add-rectangle-sum-2.test.cpp
  - icon: ':x:'
    path: test/verify/yukicoder-1826.test.cpp
    title: test/verify/yukicoder-1826.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/abstract-binary-indexed-tree.md
    document_title: "Abstract Binary Indexed Tree(\u62BD\u8C61\u5316BIT)"
    links: []
  bundledCode: "#line 1 \"structure/others/abstract-binary-indexed-tree.hpp\"\n/**\n\
    \ * @brief Abstract Binary Indexed Tree(\u62BD\u8C61\u5316BIT)\n * @docs docs/abstract-binary-indexed-tree.md\n\
    \ */\ntemplate< typename T, typename F >\nstruct AbstractBinaryIndexedTree {\n\
    private:\n  int n;\n  vector< T > data;\n  const F f;\n  const T e;\n\npublic:\n\
    \  AbstractBinaryIndexedTree() = default;\n\n  explicit AbstractBinaryIndexedTree(int\
    \ n, const F f, const T &e) : n(n), f(f), e(e) {\n    data.assign(n + 1, e);\n\
    \  }\n\n  explicit AbstractBinaryIndexedTree(const vector< T > &v, const F f,\
    \ const T &e) :\n      AbstractBinaryIndexedTree((int) v.size(), f, e) {\n   \
    \ build(v);\n  }\n\n  void build(const vector< T > &v) {\n    assert(n == (int)\
    \ v.size());\n    for(int i = 1; i <= n; i++) data[i] = v[i - 1];\n    for(int\
    \ i = 1; i <= n; i++) {\n      int j = i + (i & -i);\n      if(j <= n) data[j]\
    \ = f(data[j], data[i]);\n    }\n  }\n\n  void apply(int k, const T &x) {\n  \
    \  for(++k; k <= n; k += k & -k) data[k] = f(data[k], x);\n  }\n\n  T prod(int\
    \ r) const {\n    T ret{e};\n    for(; r > 0; r -= r & -r) ret = f(ret, data[r]);\n\
    \    return ret;\n  }\n};\n\ntemplate< typename T, typename F >\nAbstractBinaryIndexedTree<\
    \ T, F > get_abstract_binary_indexed_tree(int n, const F &f, const T &e) {\n \
    \ return AbstractBinaryIndexedTree{n, f, e};\n}\n\ntemplate< typename T, typename\
    \ F >\nAbstractBinaryIndexedTree< T, F > get_abstract_binary_indexed_tree(const\
    \ vector< T > &v, const F &f, const T &e) {\n  return AbstractBinaryIndexedTree{v,\
    \ f, e};\n}\n"
  code: "/**\n * @brief Abstract Binary Indexed Tree(\u62BD\u8C61\u5316BIT)\n * @docs\
    \ docs/abstract-binary-indexed-tree.md\n */\ntemplate< typename T, typename F\
    \ >\nstruct AbstractBinaryIndexedTree {\nprivate:\n  int n;\n  vector< T > data;\n\
    \  const F f;\n  const T e;\n\npublic:\n  AbstractBinaryIndexedTree() = default;\n\
    \n  explicit AbstractBinaryIndexedTree(int n, const F f, const T &e) : n(n), f(f),\
    \ e(e) {\n    data.assign(n + 1, e);\n  }\n\n  explicit AbstractBinaryIndexedTree(const\
    \ vector< T > &v, const F f, const T &e) :\n      AbstractBinaryIndexedTree((int)\
    \ v.size(), f, e) {\n    build(v);\n  }\n\n  void build(const vector< T > &v)\
    \ {\n    assert(n == (int) v.size());\n    for(int i = 1; i <= n; i++) data[i]\
    \ = v[i - 1];\n    for(int i = 1; i <= n; i++) {\n      int j = i + (i & -i);\n\
    \      if(j <= n) data[j] = f(data[j], data[i]);\n    }\n  }\n\n  void apply(int\
    \ k, const T &x) {\n    for(++k; k <= n; k += k & -k) data[k] = f(data[k], x);\n\
    \  }\n\n  T prod(int r) const {\n    T ret{e};\n    for(; r > 0; r -= r & -r)\
    \ ret = f(ret, data[r]);\n    return ret;\n  }\n};\n\ntemplate< typename T, typename\
    \ F >\nAbstractBinaryIndexedTree< T, F > get_abstract_binary_indexed_tree(int\
    \ n, const F &f, const T &e) {\n  return AbstractBinaryIndexedTree{n, f, e};\n\
    }\n\ntemplate< typename T, typename F >\nAbstractBinaryIndexedTree< T, F > get_abstract_binary_indexed_tree(const\
    \ vector< T > &v, const F &f, const T &e) {\n  return AbstractBinaryIndexedTree{v,\
    \ f, e};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/others/abstract-binary-indexed-tree.hpp
  requiredBy:
  - structure/others/abstract-2d-binary-indexed-tree-compressed.hpp
  timestamp: '2022-09-11 00:53:50+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/verify/yukicoder-1826.test.cpp
  - test/verify/yosupo-point-add-rectangle-sum-2.test.cpp
documentation_of: structure/others/abstract-binary-indexed-tree.hpp
layout: document
redirect_from:
- /library/structure/others/abstract-binary-indexed-tree.hpp
- /library/structure/others/abstract-binary-indexed-tree.hpp.html
title: "Abstract Binary Indexed Tree(\u62BD\u8C61\u5316BIT)"
---
