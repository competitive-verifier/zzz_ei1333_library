---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj-1508-3.test.cpp
    title: test/verify/aoj-1508-3.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Weight-Balanced-Tree(\u91CD\u307F\u5E73\u8861\u6728)"
    links: []
  bundledCode: "#line 1 \"structure/bbst/weight-balanced-tree.hpp\"\n/**\n * @brief\
    \ Weight-Balanced-Tree(\u91CD\u307F\u5E73\u8861\u6728)\n */\ntemplate< typename\
    \ Monoid, typename F >\nstruct WeightBalancedTree {\npublic:\n  struct Node {\n\
    \    Node *l, *r;\n    int cnt;\n    Monoid key, sum;\n\n    Node() {}\n\n   \
    \ Node(const Monoid &k) : key(k), sum(k), l(nullptr), r(nullptr), cnt(1) {}\n\n\
    \    Node(Node *l, Node *r, const Monoid &k) : key(k), l(l), r(r) {}\n\n    bool\
    \ is_leaf() { return !l || !r; }\n  };\n\nprivate:\n  Node *update(Node *t) {\n\
    \    t->cnt = count(t->l) + count(t->r) + t->is_leaf();\n    t->sum = f(f(sum(t->l),\
    \ t->key), sum(t->r));\n    return t;\n  }\n\n  inline Node *alloc(Node *l, Node\
    \ *r) {\n    auto t = &(*pool.alloc() = Node(l, r, M1));\n    return update(t);\n\
    \  }\n\n  Node *submerge(Node *l, Node *r) {\n    if(count(l) > count(r) * 4)\
    \ {\n      l = clone(l);\n      auto nl = clone(l->l);\n      auto nr = submerge(l->r,\
    \ r);\n      if(count(nl) * 4 >= count(nr)) {\n        l->r = nr;\n        return\
    \ update(l);\n      }\n      if(count(nr->l) * 3 <= count(nr->r) * 5) {\n    \
    \    l->r = nr->l;\n        nr->l = l;\n        update(l);\n        return update(nr);\n\
    \      }\n      Node *t = clone(nr->l);\n      l->r = nr->l->l;\n      update(l);\n\
    \      nr->l = nr->l->r;\n      update(nr);\n      t->l = l;\n      t->r = nr;\n\
    \      return update(t);\n    }\n    if(count(l) * 4 < count(r)) {\n      r =\
    \ clone(r);\n      auto nl = submerge(l, r->l);\n      auto nr = clone(r->r);\n\
    \      if(count(nl) <= count(nr) * 4) {\n        r->l = nl;\n        return update(r);\n\
    \      }\n      if(count(nl->l) * 5 >= count(nl->r) * 3) {\n        r->l = nl->r;\n\
    \        nl->r = r;\n        update(r);\n        return update(nl);\n      }\n\
    \      Node *t = clone(nl->r);\n      r->l = nl->r->r;\n      update(r);\n   \
    \   nl->r = nl->r->l;\n      update(nl);\n      t->r = r;\n      t->l = nl;\n\
    \      return update(t);\n    }\n    return alloc(l, r);\n  }\n\n  Node *build(int\
    \ l, int r, const vector< Monoid > &v) {\n    if(l + 1 >= r) return alloc(v[l]);\n\
    \    return merge(build(l, (l + r) >> 1, v), build((l + r) >> 1, r, v));\n  }\n\
    \n  void dump(Node *r, typename vector< Monoid >::iterator &it) {\n    if(r->is_leaf())\
    \ {\n      *it++ = r->key;\n      return;\n    }\n    dump(r->l, it);\n    dump(r->r,\
    \ it);\n  }\n\n  virtual Node *clone(Node *t) {\n    return t;\n  }\n\n  Node\
    \ *merge(Node *l) {\n    return l;\n  }\n\n  Monoid query(Node *t, int a, int\
    \ b, int l, int r) {\n    if(r <= a || b <= l) return M1;\n    if(a <= l && r\
    \ <= b) return t->sum;\n    return f(query(t->l, a, b, l, l + count(t->l)), query(t->r,\
    \ a, b, r - count(t->r), r));\n  }\n\npublic:\n  VectorPool< Node > pool;\n  const\
    \ F f;\n  const Monoid M1;\n\n  WeightBalancedTree(int sz, const F &f, const Monoid\
    \ &M1) : pool(sz), M1(M1), f(f) {\n    pool.clear();\n  }\n\n  inline Node *alloc(const\
    \ Monoid &key) {\n    return &(*pool.alloc() = Node(key));\n  }\n\n  static inline\
    \ int count(const Node *t) { return t ? t->cnt : 0; }\n\n  inline const Monoid\
    \ &sum(const Node *t) { return t ? t->sum : M1; }\n\n  pair< Node *, Node * >\
    \ split(Node *t, int k) {\n    if(!t) return {nullptr, nullptr};\n    if(k ==\
    \ 0) return {nullptr, t};\n    if(k >= count(t)) return {t, nullptr};\n    t =\
    \ clone(t);\n    Node *l = t->l, *r = t->r;\n    pool.free(t);\n    if(k < count(l))\
    \ {\n      auto pp = split(l, k);\n      return {pp.first, merge(pp.second, r)};\n\
    \    }\n    if(k > count(l)) {\n      auto pp = split(r, k - count(l));\n    \
    \  return {merge(l, pp.first), pp.second};\n    }\n    return {l, r};\n  }\n\n\
    \  tuple< Node *, Node *, Node * > split3(Node *t, int a, int b) {\n    auto x\
    \ = split(t, a);\n    auto y = split(x.second, b - a);\n    return make_tuple(x.first,\
    \ y.first, y.second);\n  }\n\n  template< typename ... Args >\n  Node *merge(Node\
    \ *l, Args ...rest) {\n    Node *r = merge(rest...);\n    if(!l || !r) return\
    \ l ? l : r;\n    return submerge(l, r);\n  }\n\n  Node *build(const vector< Monoid\
    \ > &v) {\n    return build(0, (int) v.size(), v);\n  }\n\n  vector< Monoid >\
    \ dump(Node *r) {\n    vector< Monoid > v((size_t) count(r));\n    auto it = begin(v);\n\
    \    dump(r, it);\n    return v;\n  }\n\n  string to_string(Node *r) {\n    auto\
    \ s = dump(r);\n    string ret;\n    for(int i = 0; i < s.size(); i++) {\n   \
    \   ret += std::to_string(s[i]);\n      ret += \", \";\n    }\n    return ret;\n\
    \  }\n\n  void insert(Node *&t, int k, const Monoid &v) {\n    auto x = split(t,\
    \ k);\n    t = merge(merge(x.first, alloc(v)), x.second);\n  }\n\n  Monoid erase(Node\
    \ *&t, int k) {\n    auto x = split(t, k);\n    auto y = split(x.second, 1);\n\
    \    auto v = y.first->c;\n    pool.free(y.first);\n    t = merge(x.first, y.second);\n\
    \    return v;\n  }\n\n  Monoid query(Node *t, int a, int b) {\n    return query(t,\
    \ a, b, 0, count(t));\n  }\n\n  void set_element(Node *&t, int k, const Monoid\
    \ &x) {\n    t = clone(t);\n    if(t->is_leaf()) {\n      t->key = t->sum = x;\n\
    \      return;\n    }\n    if(k < count(t->l)) set_element(t->l, k, x);\n    else\
    \ set_element(t->r, k - count(t->l), x);\n    t = update(t);\n  }\n\n  void push_front(Node\
    \ *&t, const Monoid &v) {\n    t = merge(alloc(v), t);\n  }\n\n  void push_back(Node\
    \ *&t, const Monoid &v) {\n    t = merge(t, alloc(v));\n  }\n\n  Monoid pop_front(Node\
    \ *&t) {\n    auto ret = split(t, 1);\n    t = ret.second;\n    return ret.first->key;\n\
    \  }\n\n  Monoid pop_back(Node *&t) {\n    auto ret = split(t, count(t) - 1);\n\
    \    t = ret.first;\n    return ret.second->key;\n  }\n};\n"
  code: "/**\n * @brief Weight-Balanced-Tree(\u91CD\u307F\u5E73\u8861\u6728)\n */\n\
    template< typename Monoid, typename F >\nstruct WeightBalancedTree {\npublic:\n\
    \  struct Node {\n    Node *l, *r;\n    int cnt;\n    Monoid key, sum;\n\n   \
    \ Node() {}\n\n    Node(const Monoid &k) : key(k), sum(k), l(nullptr), r(nullptr),\
    \ cnt(1) {}\n\n    Node(Node *l, Node *r, const Monoid &k) : key(k), l(l), r(r)\
    \ {}\n\n    bool is_leaf() { return !l || !r; }\n  };\n\nprivate:\n  Node *update(Node\
    \ *t) {\n    t->cnt = count(t->l) + count(t->r) + t->is_leaf();\n    t->sum =\
    \ f(f(sum(t->l), t->key), sum(t->r));\n    return t;\n  }\n\n  inline Node *alloc(Node\
    \ *l, Node *r) {\n    auto t = &(*pool.alloc() = Node(l, r, M1));\n    return\
    \ update(t);\n  }\n\n  Node *submerge(Node *l, Node *r) {\n    if(count(l) > count(r)\
    \ * 4) {\n      l = clone(l);\n      auto nl = clone(l->l);\n      auto nr = submerge(l->r,\
    \ r);\n      if(count(nl) * 4 >= count(nr)) {\n        l->r = nr;\n        return\
    \ update(l);\n      }\n      if(count(nr->l) * 3 <= count(nr->r) * 5) {\n    \
    \    l->r = nr->l;\n        nr->l = l;\n        update(l);\n        return update(nr);\n\
    \      }\n      Node *t = clone(nr->l);\n      l->r = nr->l->l;\n      update(l);\n\
    \      nr->l = nr->l->r;\n      update(nr);\n      t->l = l;\n      t->r = nr;\n\
    \      return update(t);\n    }\n    if(count(l) * 4 < count(r)) {\n      r =\
    \ clone(r);\n      auto nl = submerge(l, r->l);\n      auto nr = clone(r->r);\n\
    \      if(count(nl) <= count(nr) * 4) {\n        r->l = nl;\n        return update(r);\n\
    \      }\n      if(count(nl->l) * 5 >= count(nl->r) * 3) {\n        r->l = nl->r;\n\
    \        nl->r = r;\n        update(r);\n        return update(nl);\n      }\n\
    \      Node *t = clone(nl->r);\n      r->l = nl->r->r;\n      update(r);\n   \
    \   nl->r = nl->r->l;\n      update(nl);\n      t->r = r;\n      t->l = nl;\n\
    \      return update(t);\n    }\n    return alloc(l, r);\n  }\n\n  Node *build(int\
    \ l, int r, const vector< Monoid > &v) {\n    if(l + 1 >= r) return alloc(v[l]);\n\
    \    return merge(build(l, (l + r) >> 1, v), build((l + r) >> 1, r, v));\n  }\n\
    \n  void dump(Node *r, typename vector< Monoid >::iterator &it) {\n    if(r->is_leaf())\
    \ {\n      *it++ = r->key;\n      return;\n    }\n    dump(r->l, it);\n    dump(r->r,\
    \ it);\n  }\n\n  virtual Node *clone(Node *t) {\n    return t;\n  }\n\n  Node\
    \ *merge(Node *l) {\n    return l;\n  }\n\n  Monoid query(Node *t, int a, int\
    \ b, int l, int r) {\n    if(r <= a || b <= l) return M1;\n    if(a <= l && r\
    \ <= b) return t->sum;\n    return f(query(t->l, a, b, l, l + count(t->l)), query(t->r,\
    \ a, b, r - count(t->r), r));\n  }\n\npublic:\n  VectorPool< Node > pool;\n  const\
    \ F f;\n  const Monoid M1;\n\n  WeightBalancedTree(int sz, const F &f, const Monoid\
    \ &M1) : pool(sz), M1(M1), f(f) {\n    pool.clear();\n  }\n\n  inline Node *alloc(const\
    \ Monoid &key) {\n    return &(*pool.alloc() = Node(key));\n  }\n\n  static inline\
    \ int count(const Node *t) { return t ? t->cnt : 0; }\n\n  inline const Monoid\
    \ &sum(const Node *t) { return t ? t->sum : M1; }\n\n  pair< Node *, Node * >\
    \ split(Node *t, int k) {\n    if(!t) return {nullptr, nullptr};\n    if(k ==\
    \ 0) return {nullptr, t};\n    if(k >= count(t)) return {t, nullptr};\n    t =\
    \ clone(t);\n    Node *l = t->l, *r = t->r;\n    pool.free(t);\n    if(k < count(l))\
    \ {\n      auto pp = split(l, k);\n      return {pp.first, merge(pp.second, r)};\n\
    \    }\n    if(k > count(l)) {\n      auto pp = split(r, k - count(l));\n    \
    \  return {merge(l, pp.first), pp.second};\n    }\n    return {l, r};\n  }\n\n\
    \  tuple< Node *, Node *, Node * > split3(Node *t, int a, int b) {\n    auto x\
    \ = split(t, a);\n    auto y = split(x.second, b - a);\n    return make_tuple(x.first,\
    \ y.first, y.second);\n  }\n\n  template< typename ... Args >\n  Node *merge(Node\
    \ *l, Args ...rest) {\n    Node *r = merge(rest...);\n    if(!l || !r) return\
    \ l ? l : r;\n    return submerge(l, r);\n  }\n\n  Node *build(const vector< Monoid\
    \ > &v) {\n    return build(0, (int) v.size(), v);\n  }\n\n  vector< Monoid >\
    \ dump(Node *r) {\n    vector< Monoid > v((size_t) count(r));\n    auto it = begin(v);\n\
    \    dump(r, it);\n    return v;\n  }\n\n  string to_string(Node *r) {\n    auto\
    \ s = dump(r);\n    string ret;\n    for(int i = 0; i < s.size(); i++) {\n   \
    \   ret += std::to_string(s[i]);\n      ret += \", \";\n    }\n    return ret;\n\
    \  }\n\n  void insert(Node *&t, int k, const Monoid &v) {\n    auto x = split(t,\
    \ k);\n    t = merge(merge(x.first, alloc(v)), x.second);\n  }\n\n  Monoid erase(Node\
    \ *&t, int k) {\n    auto x = split(t, k);\n    auto y = split(x.second, 1);\n\
    \    auto v = y.first->c;\n    pool.free(y.first);\n    t = merge(x.first, y.second);\n\
    \    return v;\n  }\n\n  Monoid query(Node *t, int a, int b) {\n    return query(t,\
    \ a, b, 0, count(t));\n  }\n\n  void set_element(Node *&t, int k, const Monoid\
    \ &x) {\n    t = clone(t);\n    if(t->is_leaf()) {\n      t->key = t->sum = x;\n\
    \      return;\n    }\n    if(k < count(t->l)) set_element(t->l, k, x);\n    else\
    \ set_element(t->r, k - count(t->l), x);\n    t = update(t);\n  }\n\n  void push_front(Node\
    \ *&t, const Monoid &v) {\n    t = merge(alloc(v), t);\n  }\n\n  void push_back(Node\
    \ *&t, const Monoid &v) {\n    t = merge(t, alloc(v));\n  }\n\n  Monoid pop_front(Node\
    \ *&t) {\n    auto ret = split(t, 1);\n    t = ret.second;\n    return ret.first->key;\n\
    \  }\n\n  Monoid pop_back(Node *&t) {\n    auto ret = split(t, count(t) - 1);\n\
    \    t = ret.first;\n    return ret.second->key;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/bbst/weight-balanced-tree.hpp
  requiredBy: []
  timestamp: '2022-09-11 00:53:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/aoj-1508-3.test.cpp
documentation_of: structure/bbst/weight-balanced-tree.hpp
layout: document
redirect_from:
- /library/structure/bbst/weight-balanced-tree.hpp
- /library/structure/bbst/weight-balanced-tree.hpp.html
title: "Weight-Balanced-Tree(\u91CD\u307F\u5E73\u8861\u6728)"
---
