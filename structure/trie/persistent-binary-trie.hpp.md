---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Persistent-Binary-Trie
    links: []
  bundledCode: "#line 1 \"structure/trie/persistent-binary-trie.hpp\"\n/**\n * @brief\
    \ Persistent-Binary-Trie\n */\ntemplate< typename T, int MAX_LOG, typename D =\
    \ int >\nstruct PersistentBinaryTrie : BinaryTrie< T, MAX_LOG, D > {\n  using\
    \ BinaryTrie< T, MAX_LOG, D >::BinaryTrie;\n  using Node = typename BinaryTrie<\
    \ T, MAX_LOG, D >::Node;\nprivate:\n  Node *clone(Node *t) { return new Node(*t);\
    \ }\n};\n"
  code: "/**\n * @brief Persistent-Binary-Trie\n */\ntemplate< typename T, int MAX_LOG,\
    \ typename D = int >\nstruct PersistentBinaryTrie : BinaryTrie< T, MAX_LOG, D\
    \ > {\n  using BinaryTrie< T, MAX_LOG, D >::BinaryTrie;\n  using Node = typename\
    \ BinaryTrie< T, MAX_LOG, D >::Node;\nprivate:\n  Node *clone(Node *t) { return\
    \ new Node(*t); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/trie/persistent-binary-trie.hpp
  requiredBy: []
  timestamp: '2022-09-11 00:53:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/trie/persistent-binary-trie.hpp
layout: document
redirect_from:
- /library/structure/trie/persistent-binary-trie.hpp
- /library/structure/trie/persistent-binary-trie.hpp.html
title: Persistent-Binary-Trie
---
