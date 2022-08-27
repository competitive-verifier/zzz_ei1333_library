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
  bundledCode: "#line 1 \"structure/bbst/persistent-lazy-red-black-tree.hpp\"\ntemplate\
    \ < typename Monoid, typename OperatorMonoid, typename F,\n           typename\
    \ G, typename H, size_t FULL = 1000 >\nstruct PersistentLazyRedBlackTree\n   \
    \ : LazyRedBlackTree< Monoid, OperatorMonoid, F, G, H > {\n  using RBT = LazyRedBlackTree<\
    \ Monoid, OperatorMonoid, F, G, H >;\n  using RBT::LazyRedBlackTree;\n  using\
    \ Node = typename RBT::Node;\n\n private:\n  Node *clone(Node *t) override {\n\
    \    return &(*RBT::pool.alloc() = *t);\n  }\n\n public:\n  Node *rebuild(Node\
    \ *r) {\n    auto ret = RBT::dump(r);\n    RBT::pool.clear();\n    return RBT::build(ret);\n\
    \  }\n\n  bool almost_full() const {\n    return this->pool.ptr < FULL;\n  }\n\
    };\n"
  code: "template < typename Monoid, typename OperatorMonoid, typename F,\n      \
    \     typename G, typename H, size_t FULL = 1000 >\nstruct PersistentLazyRedBlackTree\n\
    \    : LazyRedBlackTree< Monoid, OperatorMonoid, F, G, H > {\n  using RBT = LazyRedBlackTree<\
    \ Monoid, OperatorMonoid, F, G, H >;\n  using RBT::LazyRedBlackTree;\n  using\
    \ Node = typename RBT::Node;\n\n private:\n  Node *clone(Node *t) override {\n\
    \    return &(*RBT::pool.alloc() = *t);\n  }\n\n public:\n  Node *rebuild(Node\
    \ *r) {\n    auto ret = RBT::dump(r);\n    RBT::pool.clear();\n    return RBT::build(ret);\n\
    \  }\n\n  bool almost_full() const {\n    return this->pool.ptr < FULL;\n  }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/bbst/persistent-lazy-red-black-tree.hpp
  requiredBy: []
  timestamp: '2022-08-27 15:55:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/bbst/persistent-lazy-red-black-tree.hpp
layout: document
redirect_from:
- /library/structure/bbst/persistent-lazy-red-black-tree.hpp
- /library/structure/bbst/persistent-lazy-red-black-tree.hpp.html
title: structure/bbst/persistent-lazy-red-black-tree.hpp
---
