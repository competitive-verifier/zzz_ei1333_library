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
  bundledCode: "#line 1 \"structure/bbst/persistent-red-black-tree.hpp\"\ntemplate<\
    \ typename Monoid, typename F, size_t FULL = 1000 >\nstruct PersistentRedBlackTree\
    \ : RedBlackTree< Monoid, F > {\n  using RBT = RedBlackTree< Monoid, F >;\n  using\
    \ RBT::RedBlackTree;\n  using Node = typename RBT::Node;\n\nprivate:\n  Node *clone(Node\
    \ *t) override {\n    return &(*RBT::pool.alloc() = *t);\n  }\n\npublic:\n  Node\
    \ *rebuild(Node *r) {\n    auto ret = RBT::dump(r);\n    RBT::pool.clear();\n\
    \    return RBT::build(ret);\n  }\n\n  bool almost_full() const {\n    return\
    \ this->pool.ptr < FULL;\n  }\n};\n"
  code: "template< typename Monoid, typename F, size_t FULL = 1000 >\nstruct PersistentRedBlackTree\
    \ : RedBlackTree< Monoid, F > {\n  using RBT = RedBlackTree< Monoid, F >;\n  using\
    \ RBT::RedBlackTree;\n  using Node = typename RBT::Node;\n\nprivate:\n  Node *clone(Node\
    \ *t) override {\n    return &(*RBT::pool.alloc() = *t);\n  }\n\npublic:\n  Node\
    \ *rebuild(Node *r) {\n    auto ret = RBT::dump(r);\n    RBT::pool.clear();\n\
    \    return RBT::build(ret);\n  }\n\n  bool almost_full() const {\n    return\
    \ this->pool.ptr < FULL;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/bbst/persistent-red-black-tree.hpp
  requiredBy: []
  timestamp: '2022-09-11 00:53:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/bbst/persistent-red-black-tree.hpp
layout: document
redirect_from:
- /library/structure/bbst/persistent-red-black-tree.hpp
- /library/structure/bbst/persistent-red-black-tree.hpp.html
title: structure/bbst/persistent-red-black-tree.hpp
---
