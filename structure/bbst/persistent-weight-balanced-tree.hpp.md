---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Persistent-Weight-Balanced-Tree(\u6C38\u7D9A\u91CD\u307F\u5E73\
      \u8861\u6728)"
    links: []
  bundledCode: "#line 1 \"structure/bbst/persistent-weight-balanced-tree.hpp\"\n/**\n\
    \ * @brief Persistent-Weight-Balanced-Tree(\u6C38\u7D9A\u91CD\u307F\u5E73\u8861\
    \u6728)\n */\ntemplate< typename Monoid, typename F, size_t FULL = 1000 >\nstruct\
    \ PersistentWeightBalancedTree : WeightBalancedTree< Monoid, F > {\n  using WBT\
    \ = WeightBalancedTree< Monoid, F >;\n  using WBT::WeightBalancedTree;\n  using\
    \ Node = typename WBT::Node;\n\nprivate:\n  Node *clone(Node *t) override {\n\
    \    return &(*WBT::pool.alloc() = *t);\n  }\n\npublic:\n  Node *rebuild(Node\
    \ *r) {\n    auto ret = WBT::dump(r);\n    WBT::pool.clear();\n    return WBT::build(ret);\n\
    \  }\n\n  bool almost_full() const {\n    return this->pool.ptr < FULL;\n  }\n\
    };\n"
  code: "/**\n * @brief Persistent-Weight-Balanced-Tree(\u6C38\u7D9A\u91CD\u307F\u5E73\
    \u8861\u6728)\n */\ntemplate< typename Monoid, typename F, size_t FULL = 1000\
    \ >\nstruct PersistentWeightBalancedTree : WeightBalancedTree< Monoid, F > {\n\
    \  using WBT = WeightBalancedTree< Monoid, F >;\n  using WBT::WeightBalancedTree;\n\
    \  using Node = typename WBT::Node;\n\nprivate:\n  Node *clone(Node *t) override\
    \ {\n    return &(*WBT::pool.alloc() = *t);\n  }\n\npublic:\n  Node *rebuild(Node\
    \ *r) {\n    auto ret = WBT::dump(r);\n    WBT::pool.clear();\n    return WBT::build(ret);\n\
    \  }\n\n  bool almost_full() const {\n    return this->pool.ptr < FULL;\n  }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/bbst/persistent-weight-balanced-tree.hpp
  requiredBy: []
  timestamp: '2022-09-11 00:53:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/bbst/persistent-weight-balanced-tree.hpp
layout: document
redirect_from:
- /library/structure/bbst/persistent-weight-balanced-tree.hpp
- /library/structure/bbst/persistent-weight-balanced-tree.hpp.html
title: "Persistent-Weight-Balanced-Tree(\u6C38\u7D9A\u91CD\u307F\u5E73\u8861\u6728\
  )"
---
