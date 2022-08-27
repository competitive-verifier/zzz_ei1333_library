---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/verify/aoj-2450-3.test.cpp
    title: test/verify/aoj-2450-3.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "Lazy-Reversible-Splay-Tree(\u9045\u5EF6\u4F1D\u642C\u53CD\u8EE2\
      \u53EF\u80FDSplay\u6728)"
    links: []
  bundledCode: "#line 1 \"structure/develop/lazy-reversible-splay-tree.hpp\"\n/**\n\
    \ * @brief Lazy-Reversible-Splay-Tree(\u9045\u5EF6\u4F1D\u642C\u53CD\u8EE2\u53EF\
    \u80FDSplay\u6728)\n */\ntemplate < typename Tp, typename Ep >\nstruct LazyReversibleSplayTreeNode\
    \ {\n  using T = Tp;\n  using E = Ep;\n  LazyReversibleSplayTreeNode *l, *r, *p;\n\
    \  T key, sum;\n  E lazy;\n  bool rev;\n  size_t sz;\n\n  LazyReversibleSplayTreeNode():\
    \ LazyReversibleSplayTreeNode(Tp()) {}\n\n  LazyReversibleSplayTreeNode(const\
    \ T &key)\n      : LazyReversibleSplayTreeNode(key, E()) {}\n\n  LazyReversibleSplayTreeNode(const\
    \ T &key, const E &lazy)\n      : key(key),\n        sum(key),\n        rev(false),\n\
    \        l(nullptr),\n        r(nullptr),\n        p(nullptr),\n        sz(1),\n\
    \        lazy(lazy) {}\n};\n\ntemplate < typename Np >\nstruct LazyReversibleSplayTree:\
    \ ReversibleSplayTree< Np > {\n public:\n public:\n  using Node  = Np;\n  using\
    \ T     = typename Node::T;\n  using E     = typename Node::E;\n  using super\
    \ = ReversibleSplayTree< Node >;\n  using F     = typename super::F;\n  using\
    \ G     = function< T(T, E) >;\n  using H     = function< E(E, E) >;\n  using\
    \ S     = typename super::S;\n  using NP    = typename super::NP;\n\n  explicit\
    \ LazyReversibleSplayTree(const F &f, const G &g, const H &h,\n              \
    \                     const S &s, const T &M1,\n                             \
    \      const E &OM0)\n      : g(g),\n        h(h),\n        OM0(OM0),\n      \
    \  super(f, s, M1) {}\n\n  using super::merge;\n  using super::splay;\n  using\
    \ super::split;\n\n  NP alloc(const T &x) {\n    return new Node(x, OM0);\n  }\n\
    \n  void push(NP t) override {\n    if (t->lazy != OM0) {\n      if (t->l) propagate(t->l,\
    \ t->lazy);\n      if (t->r) propagate(t->r, t->lazy);\n      t->lazy = OM0;\n\
    \    }\n    super::push(t);\n  }\n\n  NP set_propagate(NP &t, int a, int b, const\
    \ E &pp) {\n    splay(t);\n    auto x = split(t, a);\n    auto y = split(x.second,\
    \ b - a);\n    set_propagate(y.first, pp);\n    return t = merge(x.first, y.first,\
    \ y.second);\n  }\n\n  void set_propagate(NP t, const E &pp) {\n    splay(t);\n\
    \    propagate(t, pp);\n    push(t);\n  }\n\n private:\n  const E OM0;\n  const\
    \ G g;\n  const H h;\n\n  void propagate(NP t, const E &x) {\n    t->lazy = h(t->lazy,\
    \ x);\n    t->key  = g(t->key, x);\n    t->sum  = g(t->sum, x);\n  }\n};\n\ntemplate\
    \ < typename T, typename E >\nusing LRST =\n    LazyReversibleSplayTree< LazyReversibleSplayTreeNode<\
    \ T, E > >;\n"
  code: "/**\n * @brief Lazy-Reversible-Splay-Tree(\u9045\u5EF6\u4F1D\u642C\u53CD\u8EE2\
    \u53EF\u80FDSplay\u6728)\n */\ntemplate < typename Tp, typename Ep >\nstruct LazyReversibleSplayTreeNode\
    \ {\n  using T = Tp;\n  using E = Ep;\n  LazyReversibleSplayTreeNode *l, *r, *p;\n\
    \  T key, sum;\n  E lazy;\n  bool rev;\n  size_t sz;\n\n  LazyReversibleSplayTreeNode():\
    \ LazyReversibleSplayTreeNode(Tp()) {}\n\n  LazyReversibleSplayTreeNode(const\
    \ T &key)\n      : LazyReversibleSplayTreeNode(key, E()) {}\n\n  LazyReversibleSplayTreeNode(const\
    \ T &key, const E &lazy)\n      : key(key),\n        sum(key),\n        rev(false),\n\
    \        l(nullptr),\n        r(nullptr),\n        p(nullptr),\n        sz(1),\n\
    \        lazy(lazy) {}\n};\n\ntemplate < typename Np >\nstruct LazyReversibleSplayTree:\
    \ ReversibleSplayTree< Np > {\n public:\n public:\n  using Node  = Np;\n  using\
    \ T     = typename Node::T;\n  using E     = typename Node::E;\n  using super\
    \ = ReversibleSplayTree< Node >;\n  using F     = typename super::F;\n  using\
    \ G     = function< T(T, E) >;\n  using H     = function< E(E, E) >;\n  using\
    \ S     = typename super::S;\n  using NP    = typename super::NP;\n\n  explicit\
    \ LazyReversibleSplayTree(const F &f, const G &g, const H &h,\n              \
    \                     const S &s, const T &M1,\n                             \
    \      const E &OM0)\n      : g(g),\n        h(h),\n        OM0(OM0),\n      \
    \  super(f, s, M1) {}\n\n  using super::merge;\n  using super::splay;\n  using\
    \ super::split;\n\n  NP alloc(const T &x) {\n    return new Node(x, OM0);\n  }\n\
    \n  void push(NP t) override {\n    if (t->lazy != OM0) {\n      if (t->l) propagate(t->l,\
    \ t->lazy);\n      if (t->r) propagate(t->r, t->lazy);\n      t->lazy = OM0;\n\
    \    }\n    super::push(t);\n  }\n\n  NP set_propagate(NP &t, int a, int b, const\
    \ E &pp) {\n    splay(t);\n    auto x = split(t, a);\n    auto y = split(x.second,\
    \ b - a);\n    set_propagate(y.first, pp);\n    return t = merge(x.first, y.first,\
    \ y.second);\n  }\n\n  void set_propagate(NP t, const E &pp) {\n    splay(t);\n\
    \    propagate(t, pp);\n    push(t);\n  }\n\n private:\n  const E OM0;\n  const\
    \ G g;\n  const H h;\n\n  void propagate(NP t, const E &x) {\n    t->lazy = h(t->lazy,\
    \ x);\n    t->key  = g(t->key, x);\n    t->sum  = g(t->sum, x);\n  }\n};\n\ntemplate\
    \ < typename T, typename E >\nusing LRST =\n    LazyReversibleSplayTree< LazyReversibleSplayTreeNode<\
    \ T, E > >;\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/develop/lazy-reversible-splay-tree.hpp
  requiredBy: []
  timestamp: '2022-08-27 15:55:50+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/verify/aoj-2450-3.test.cpp
documentation_of: structure/develop/lazy-reversible-splay-tree.hpp
layout: document
redirect_from:
- /library/structure/develop/lazy-reversible-splay-tree.hpp
- /library/structure/develop/lazy-reversible-splay-tree.hpp.html
title: "Lazy-Reversible-Splay-Tree(\u9045\u5EF6\u4F1D\u642C\u53CD\u8EE2\u53EF\u80FD\
  Splay\u6728)"
---
