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
  bundledCode: "#line 1 \"structure/develop/splay-tree.hpp\"\ntemplate< typename key_t,\
    \ size_t V >\nstruct SplayTree {\n\n  const key_t e;\n\n  SplayTree() : pool(),\
    \ e(key_t()) {}\n\n  struct Node {\n    Node *l, *r, *p;\n    key_t sum;\n\n \
    \   Node() = default;\n\n    explicit Node(const key_t &k) : sum(k), l(nullptr),\
    \ r(nullptr), p(nullptr) {}\n  };\n\n  ArrayPool< Node, V > pool;\n\nprivate:\n\
    \  void rotr(Node *t) {\n    auto *x = t->p, *y = x->p;\n    if((x->l = t->r))\
    \ t->r->p = x;\n    t->r = x, x->p = t;\n    update(x), update(t);\n    if((t->p\
    \ = y)) {\n      if(y->l == x) y->l = t;\n      if(y->r == x) y->r = t;\n    \
    \  update(y);\n    }\n  }\n\n  void rotl(Node *t) {\n    auto *x = t->p, *y =\
    \ x->p;\n    if((x->r = t->l)) t->l->p = x;\n    t->l = x, x->p = t;\n    update(x),\
    \ update(t);\n    if((t->p = y)) {\n      if(y->l == x) y->l = t;\n      if(y->r\
    \ == x) y->r = t;\n      update(y);\n    }\n  }\n\n  void update(Node *t) {\n\
    \    t->sum.set_sum();\n    if(t->l) t->sum.update(t->l->sum);\n    if(t->r) t->sum.update(t->r->sum);\n\
    \  }\n\n  Node *get_right(Node *t) const {\n    while(t->r) t = t->r;\n    return\
    \ t;\n  }\n\n  inline Node *alloc(const key_t &v) {\n    auto p = &(*pool.alloc()\
    \ = Node(v));\n    update(p);\n    return p;\n  }\n\n  void splay(Node *t) {\n\
    \    while(t->p) {\n      auto *q = t->p;\n      if(!q->p) {\n        if(q->l\
    \ == t) rotr(t);\n        else rotl(t);\n      } else {\n        auto *r = q->p;\n\
    \        if(r->l == q) {\n          if(q->l == t) rotr(q), rotr(t);\n        \
    \  else rotl(t), rotr(t);\n        } else {\n          if(q->r == t) rotl(q),\
    \ rotl(t);\n          else rotr(t), rotl(t);\n        }\n      }\n    }\n  }\n\
    \npublic:\n  inline const key_t &sum(Node *t) {\n    return t ? t->sum : e;\n\
    \  }\n\n  Node *push_back(Node *t, const key_t &v) {\n    if(!t) {\n      t =\
    \ alloc(v);\n      return t;\n    } else {\n      Node *cur = get_right(t), *z\
    \ = alloc(v);\n      z->p = cur;\n      cur->r = z;\n      update(cur);\n    \
    \  splay(z);\n      return z;\n    }\n  }\n\n  Node *erase(Node *t) {\n    splay(t);\n\
    \    Node *x = t->l, *y = t->r;\n    pool.free(t);\n    if(!x) {\n      t = y;\n\
    \      if(t) t->p = nullptr;\n    } else if(!y) {\n      t = x;\n      t->p =\
    \ nullptr;\n    } else {\n      x->p = nullptr;\n      t = get_right(x);\n   \
    \   splay(t);\n      t->r = y;\n      y->p = t;\n      update(t);\n    }\n   \
    \ return t;\n  }\n};\n"
  code: "template< typename key_t, size_t V >\nstruct SplayTree {\n\n  const key_t\
    \ e;\n\n  SplayTree() : pool(), e(key_t()) {}\n\n  struct Node {\n    Node *l,\
    \ *r, *p;\n    key_t sum;\n\n    Node() = default;\n\n    explicit Node(const\
    \ key_t &k) : sum(k), l(nullptr), r(nullptr), p(nullptr) {}\n  };\n\n  ArrayPool<\
    \ Node, V > pool;\n\nprivate:\n  void rotr(Node *t) {\n    auto *x = t->p, *y\
    \ = x->p;\n    if((x->l = t->r)) t->r->p = x;\n    t->r = x, x->p = t;\n    update(x),\
    \ update(t);\n    if((t->p = y)) {\n      if(y->l == x) y->l = t;\n      if(y->r\
    \ == x) y->r = t;\n      update(y);\n    }\n  }\n\n  void rotl(Node *t) {\n  \
    \  auto *x = t->p, *y = x->p;\n    if((x->r = t->l)) t->l->p = x;\n    t->l =\
    \ x, x->p = t;\n    update(x), update(t);\n    if((t->p = y)) {\n      if(y->l\
    \ == x) y->l = t;\n      if(y->r == x) y->r = t;\n      update(y);\n    }\n  }\n\
    \n  void update(Node *t) {\n    t->sum.set_sum();\n    if(t->l) t->sum.update(t->l->sum);\n\
    \    if(t->r) t->sum.update(t->r->sum);\n  }\n\n  Node *get_right(Node *t) const\
    \ {\n    while(t->r) t = t->r;\n    return t;\n  }\n\n  inline Node *alloc(const\
    \ key_t &v) {\n    auto p = &(*pool.alloc() = Node(v));\n    update(p);\n    return\
    \ p;\n  }\n\n  void splay(Node *t) {\n    while(t->p) {\n      auto *q = t->p;\n\
    \      if(!q->p) {\n        if(q->l == t) rotr(t);\n        else rotl(t);\n  \
    \    } else {\n        auto *r = q->p;\n        if(r->l == q) {\n          if(q->l\
    \ == t) rotr(q), rotr(t);\n          else rotl(t), rotr(t);\n        } else {\n\
    \          if(q->r == t) rotl(q), rotl(t);\n          else rotr(t), rotl(t);\n\
    \        }\n      }\n    }\n  }\n\npublic:\n  inline const key_t &sum(Node *t)\
    \ {\n    return t ? t->sum : e;\n  }\n\n  Node *push_back(Node *t, const key_t\
    \ &v) {\n    if(!t) {\n      t = alloc(v);\n      return t;\n    } else {\n  \
    \    Node *cur = get_right(t), *z = alloc(v);\n      z->p = cur;\n      cur->r\
    \ = z;\n      update(cur);\n      splay(z);\n      return z;\n    }\n  }\n\n \
    \ Node *erase(Node *t) {\n    splay(t);\n    Node *x = t->l, *y = t->r;\n    pool.free(t);\n\
    \    if(!x) {\n      t = y;\n      if(t) t->p = nullptr;\n    } else if(!y) {\n\
    \      t = x;\n      t->p = nullptr;\n    } else {\n      x->p = nullptr;\n  \
    \    t = get_right(x);\n      splay(t);\n      t->r = y;\n      y->p = t;\n  \
    \    update(t);\n    }\n    return t;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/develop/splay-tree.hpp
  requiredBy: []
  timestamp: '2022-07-05 18:16:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/develop/splay-tree.hpp
layout: document
redirect_from:
- /library/structure/develop/splay-tree.hpp
- /library/structure/develop/splay-tree.hpp.html
title: structure/develop/splay-tree.hpp
---
