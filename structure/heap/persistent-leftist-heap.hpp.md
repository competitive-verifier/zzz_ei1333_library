---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/verify/yosupo-k-shortest-walk.test.cpp
    title: test/verify/yosupo-k-shortest-walk.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Persistent-Leftist-Heap
    links: []
  bundledCode: "#line 1 \"structure/heap/persistent-leftist-heap.hpp\"\n/**\n * @brief\
    \ Persistent-Leftist-Heap\n */\ntemplate< typename T, bool isMin = true >\nstruct\
    \ PersistentLeftistHeap : LeftistHeap< T, isMin > {\n  using Node = typename LeftistHeap<\
    \ T, isMin >::Node;\n\n  Node *clone(Node *t) override {\n    return new Node(*t);\n\
    \  }\n};\n"
  code: "/**\n * @brief Persistent-Leftist-Heap\n */\ntemplate< typename T, bool isMin\
    \ = true >\nstruct PersistentLeftistHeap : LeftistHeap< T, isMin > {\n  using\
    \ Node = typename LeftistHeap< T, isMin >::Node;\n\n  Node *clone(Node *t) override\
    \ {\n    return new Node(*t);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/heap/persistent-leftist-heap.hpp
  requiredBy: []
  timestamp: '2022-09-11 00:53:50+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/verify/yosupo-k-shortest-walk.test.cpp
documentation_of: structure/heap/persistent-leftist-heap.hpp
layout: document
redirect_from:
- /library/structure/heap/persistent-leftist-heap.hpp
- /library/structure/heap/persistent-leftist-heap.hpp.html
title: Persistent-Leftist-Heap
---
