---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: structure/develop/diameter.hpp
    title: Diameter
  - icon: ':x:'
    path: structure/develop/dynamic-tree-test.hpp
    title: Dynamic Tree Test
  - icon: ':x:'
    path: structure/develop/subtree-add-subtree-sum.hpp
    title: Subtree Add Subtree Sum
  - icon: ':x:'
    path: structure/develop/vertex-set-path-composite.hpp
    title: Vertex Set Path Composite
  - icon: ':x:'
    path: structure/develop/vertex-set-path-sum.hpp
    title: Vertex Set Path Sum
  - icon: ':x:'
    path: structure/develop/vertex-set-subtree-sum.hpp
    title: Vertex Set Subtree Sum
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/verify/aoj-2450-4.test.cpp
    title: test/verify/aoj-2450-4.test.cpp
  - icon: ':x:'
    path: test/verify/aoj-grl-5-a-2.test.cpp
    title: test/verify/aoj-grl-5-a-2.test.cpp
  - icon: ':x:'
    path: test/verify/dmoj-ds5.test.cpp
    title: test/verify/dmoj-ds5.test.cpp
  - icon: ':x:'
    path: test/verify/yosupo-dynamic-tree-subtree-add-subtree-sum.test.cpp
    title: test/verify/yosupo-dynamic-tree-subtree-add-subtree-sum.test.cpp
  - icon: ':x:'
    path: test/verify/yosupo-dynamic-tree-vertex-add-path-sum-3.test.cpp
    title: test/verify/yosupo-dynamic-tree-vertex-add-path-sum-3.test.cpp
  - icon: ':x:'
    path: test/verify/yosupo-dynamic-tree-vertex-add-subtree-sum-2.test.cpp
    title: test/verify/yosupo-dynamic-tree-vertex-add-subtree-sum-2.test.cpp
  - icon: ':x:'
    path: test/verify/yosupo-dynamic-tree-vertex-set-path-composite-3.test.cpp
    title: test/verify/yosupo-dynamic-tree-vertex-set-path-composite-3.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "\u4F55\u3067\u3082\u3067\u304D\u308BLCT"
    links: []
  bundledCode: "#line 1 \"structure/develop/super-link-cut-tree.hpp\"\n/**\n * @brief\
    \ \u4F55\u3067\u3082\u3067\u304D\u308BLCT\n */\ntemplate < typename LInfo, typename\
    \ Lazy >\nstruct SplayTree {\n  struct Node {\n    Node *l, *r, *p;\n    LInfo\
    \ info;\n    Lazy lazy, lbuf;\n\n    explicit Node(const LInfo &info)\n      \
    \  : info(info),\n          l(nullptr),\n          r(nullptr),\n          p(nullptr),\n\
    \          lazy(Lazy()),\n          lbuf(Lazy()) {}\n  };\n\n  const LInfo e;\n\
    \n  SplayTree(): e(LInfo()) {}\n\n  using NP = Node *;\n\n  void rotr(NP t) {\n\
    \    NP x = t->p, y = x->p;\n    push(x), push(t);\n    if ((x->l = t->r)) t->r->p\
    \ = x;\n    t->r = x, x->p = t;\n    update(x), update(t);\n    if ((t->p = y))\
    \ {\n      if (y->l == x) y->l = t;\n      if (y->r == x) y->r = t;\n    }\n \
    \ }\n\n  void rotl(NP t) {\n    NP x = t->p, y = x->p;\n    push(x), push(t);\n\
    \    if ((x->r = t->l)) t->l->p = x;\n    t->l = x, x->p = t;\n    update(x),\
    \ update(t);\n    if ((t->p = y)) {\n      if (y->l == x) y->l = t;\n      if\
    \ (y->r == x) y->r = t;\n    }\n  }\n\n  const LInfo &get_info(NP t) {\n    return\
    \ t ? t->info : e;\n  }\n\n  void update(NP t) {\n    t->info.update(get_info(t->l),\
    \ get_info(t->r));\n  }\n\n  NP get_right(NP t) {\n    while (t->r) t = t->r;\n\
    \    return t;\n  }\n\n  NP alloc(const LInfo &v) {\n    auto t = new Node(v);\n\
    \    update(t);\n    return t;\n  }\n\n  void propagate(NP t, const Lazy &lazy)\
    \ {\n    t->info.propagate(lazy);\n    t->lbuf.propagate(lazy);\n    t->lazy.propagate(lazy);\n\
    \  }\n\n  void push(NP t) {\n    if (t->l) propagate(t->l, t->lazy);\n    if (t->r)\
    \ propagate(t->r, t->lazy);\n    t->lazy = Lazy();\n  }\n\n  void splay(NP t)\
    \ {\n    push(t);\n    while (t->p) {\n      NP q = t->p;\n      if (!q->p) {\n\
    \        if (q->l == t)\n          rotr(t);\n        else\n          rotl(t);\n\
    \      } else {\n        NP r = q->p;\n        if (r->l == q) {\n          if\
    \ (q->l == t)\n            rotr(q), rotr(t);\n          else\n            rotl(t),\
    \ rotr(t);\n        } else {\n          if (q->r == t)\n            rotl(q), rotl(t);\n\
    \          else\n            rotr(t), rotl(t);\n        }\n      }\n    }\n  }\n\
    \n  NP insert(NP t, const LInfo &v) {\n    if (not t) {\n      t = alloc(v);\n\
    \      return t;\n    } else {\n      NP cur = get_right(t), z = alloc(v);\n \
    \     splay(cur);\n      z->p   = cur;\n      cur->r = z;\n      update(cur);\n\
    \      splay(z);\n      return z;\n    }\n  }\n\n  NP erase(NP t) {\n    splay(t);\n\
    \    NP x = t->l, y = t->r;\n    delete t;\n    if (not x) {\n      t = y;\n \
    \     if (t) t->p = nullptr;\n    } else if (not y) {\n      t    = x;\n     \
    \ t->p = nullptr;\n    } else {\n      x->p = nullptr;\n      t    = get_right(x);\n\
    \      splay(t);\n      t->r = y;\n      y->p = t;\n      update(t);\n    }\n\
    \    return t;\n  }\n};\n\ntemplate < template < typename, typename > typename\
    \ _Info,\n           template < typename > typename _LInfo, typename Lazy >\n\
    struct SuperLinkCutTree {\n  using LInfo = _LInfo< Lazy >;\n  using Info  = _Info<\
    \ LInfo, Lazy >;\n\n private:\n  struct Node {\n    Node *l, *r, *p;\n    Info\
    \ info;\n    typename SplayTree< LInfo, Lazy >::Node *light, *belong;\n    bool\
    \ rev;\n    Lazy hlazy, llazy;\n\n    bool is_root() const {\n      return not\
    \ p or (p->l != this and p->r != this);\n    }\n\n    explicit Node(const Info\
    \ &info)\n        : info(info),\n          l(nullptr),\n          r(nullptr),\n\
    \          p(nullptr),\n          rev(false),\n          light(nullptr),\n   \
    \       belong(nullptr),\n          hlazy(Lazy()),\n          llazy(Lazy()) {}\n\
    \  };\n\n public:\n  using NP = Node *;\n  SplayTree< LInfo, Lazy > splay_tree;\n\
    \n private:\n  const Info e;\n\n private:\n  void toggle(NP t) {\n    swap(t->l,\
    \ t->r);\n    t->info.toggle();\n    t->rev ^= true;\n  }\n\n  void rotr(NP t)\
    \ {\n    NP x = t->p, y = x->p;\n    push(x), push(t);\n    if ((x->l = t->r))\
    \ t->r->p = x;\n    t->r = x, x->p = t;\n    update(x), update(t);\n    if ((t->p\
    \ = y)) {\n      if (y->l == x) y->l = t;\n      if (y->r == x) y->r = t;\n  \
    \  }\n  }\n\n  void rotl(NP t) {\n    NP x = t->p, y = x->p;\n    push(x), push(t);\n\
    \    if ((x->r = t->l)) t->l->p = x;\n    t->l = x, x->p = t;\n    update(x),\
    \ update(t);\n    if ((t->p = y)) {\n      if (y->l == x) y->l = t;\n      if\
    \ (y->r == x) y->r = t;\n    }\n  }\n\n  void propagate_heavy(NP t, const Lazy\
    \ &hlazy) {\n    t->hlazy.propagate(hlazy);\n    t->info.propagate(hlazy);\n \
    \ }\n\n  void propagate_light(NP t, const Lazy &llazy) {\n    t->llazy.propagate(llazy);\n\
    \    t->info.propagate_light(llazy);\n  }\n\n  void propagate_all(NP t, const\
    \ Lazy &lazy) {\n    propagate_heavy(t, lazy);\n    propagate_light(t, lazy);\n\
    \  }\n\n public:\n  SuperLinkCutTree(): e{Info()}, splay_tree{} {}\n\n  void push(NP\
    \ t) {\n    if (t->rev) {\n      if (t->l) toggle(t->l);\n      if (t->r) toggle(t->r);\n\
    \      t->rev = false;\n    }\n    {\n      if (t->l) {\n        propagate_heavy(t->l,\
    \ t->hlazy);\n        propagate_light(t->l, t->llazy);\n      }\n      if (t->r)\
    \ {\n        propagate_heavy(t->r, t->hlazy);\n        propagate_light(t->r, t->llazy);\n\
    \      }\n      if (t->light) {\n        splay_tree.propagate(t->light, t->llazy);\n\
    \      }\n      t->hlazy = Lazy();\n      t->llazy = Lazy();\n    }\n  }\n\n \
    \ void push_rev(NP t) {\n    if (t->rev) {\n      if (t->l) toggle(t->l);\n  \
    \    if (t->r) toggle(t->r);\n      t->rev = false;\n    }\n  }\n\n  const Info\
    \ &get_info(NP t) {\n    return t ? t->info : e;\n  }\n\n  void update(NP t) {\n\
    \    t->info.update(get_info(t->l), get_info(t->r),\n                   splay_tree.get_info(t->light));\n\
    \  }\n\n  void splay(NP t) {\n    push(t);\n    {\n      NP rot = t;\n      while\
    \ (not rot->is_root()) rot = rot->p;\n      t->belong = rot->belong;\n      if\
    \ (t != rot) rot->belong = nullptr;\n    }\n    while (not t->is_root()) {\n \
    \     NP q = t->p;\n      if (q->is_root()) {\n        push_rev(q), push_rev(t);\n\
    \        if (q->l == t)\n          rotr(t);\n        else\n          rotl(t);\n\
    \      } else {\n        NP r = q->p;\n        push_rev(r), push_rev(q), push_rev(t);\n\
    \        if (r->l == q) {\n          if (q->l == t)\n            rotr(q), rotr(t);\n\
    \          else\n            rotl(t), rotr(t);\n        } else {\n          if\
    \ (q->r == t)\n            rotl(q), rotl(t);\n          else\n            rotr(t),\
    \ rotl(t);\n        }\n      }\n    }\n  }\n\n  NP expose(NP t) {\n    NP rp =\
    \ nullptr;\n    for (NP cur = t; cur; cur = cur->p) {\n      splay(cur);\n   \
    \   if (cur->r) {\n        cur->light =\n            splay_tree.insert(cur->light,\
    \ cur->r->info.link());\n        cur->r->belong = cur->light;\n      }\n     \
    \ cur->r = rp;\n      if (cur->r) {\n        splay_tree.splay(cur->r->belong);\n\
    \        propagate_all(cur->r, cur->r->belong->lbuf);\n        push(cur->r);\n\
    \        cur->light = splay_tree.erase(cur->r->belong);\n      }\n      update(cur);\n\
    \      rp = cur;\n    }\n    splay(t);\n    return rp;\n  }\n\n  void link(NP\
    \ child, NP parent) {\n    expose(parent);\n    expose(child);\n    child->p \
    \ = parent;\n    parent->r = child;\n    update(parent);\n  }\n\n  void cut(NP\
    \ child) {\n    expose(child);\n    NP parent = child->l;\n    child->l  = nullptr;\n\
    \    parent->p = nullptr;\n    update(child);\n  }\n\n  void evert(NP t) {\n \
    \   expose(t);\n    toggle(t);\n    push(t);\n  }\n\n  NP alloc(const Info &info)\
    \ {\n    NP t = new Node(info);\n    update(t);\n    return t;\n  }\n\n  bool\
    \ is_connected(NP u, NP v) {\n    expose(u), expose(v);\n    return u == v or\
    \ u->p;\n  }\n\n  vector< NP > build(vector< Info > &vs) {\n    vector< NP > nodes(vs.size());\n\
    \    for (int i = 0; i < (int)vs.size(); i++) {\n      nodes[i] = alloc(vs[i]);\n\
    \    }\n    return nodes;\n  }\n\n  NP lca(NP u, NP v) {\n    if (not is_connected(u,\
    \ v)) return nullptr;\n    expose(u);\n    return expose(v);\n  }\n\n  void set_key(NP\
    \ t, const Info &v) {\n    expose(t);\n    t->info = move(v);\n    update(t);\n\
    \  }\n\n  void set_propagate_path(NP t, const Lazy &lazy) {\n    expose(t);\n\
    \    propagate_heavy(t, lazy);\n    push(t);\n    update(t);\n  }\n\n  void set_propagate_path(NP\
    \ u, NP v, const Lazy &lazy) {\n    evert(u);\n    set_propagate_path(v, lazy);\n\
    \  }\n\n  void set_propagate_all(NP t, const Lazy &lazy) {\n    expose(t);\n \
    \   propagate_all(t, lazy);\n    push(t);\n    update(t);\n  }\n\n  void set_propagate_subtree(NP\
    \ t, const Lazy &lazy) {\n    expose(t);\n    NP l = t->l;\n    t->l = nullptr;\n\
    \    propagate_all(t, lazy);\n    push(t);\n    t->l = l;\n    update(t);\n  }\n\
    \n  const Info &query(NP u) {\n    expose(u);\n    return get_info(u);\n  }\n\n\
    \  const Info &query_path(NP u, NP v) {\n    evert(u);\n    expose(v);\n    return\
    \ get_info(v);\n  }\n\n  Info query_subtree(NP u) {\n    expose(u);\n    NP l\
    \ = u->l;\n    u->l = nullptr;\n    update(u);\n    auto ret = u->info;\n    u->l\
    \     = l;\n    update(u);\n    return ret;\n  }\n};\n\n/*\nusing T = int64_t;\n\
    // \u9045\u5EF6\u4F1D\u642C\u3092\u3059\u308B\u305F\u3081\u306E\u4F5C\u7528\u7D20\
    \nstruct Lazy {\n\n  // \u5358\u4F4D\u5143\n  Lazy() {}\n\n  // \u521D\u671F\u5316\
    \n  Lazy(T v) {}\n\n  // \u9045\u5EF6\u4F1D\u642C\n  void propagate(const Lazy\
    \ &p) {}\n};\n\n// Light-edge \u306E\u60C5\u5831\ntemplate< typename Lazy >\n\
    struct LInfo {\n\n  // \u5358\u4F4D\u5143(\u30AD\u30FC\u306E\u5024\u306F\u30A2\
    \u30AF\u30BB\u30B9\u3057\u306A\u3044\u306E\u3067\u672A\u521D\u671F\u5316\u3067\
    \u3082\u3088\u3044\n  LInfo() {}\n\n  // \u521D\u671F\u5316\n  LInfo(T v) {}\n\
    \n  // l, r \u306F Splay-tree \u306E\u5B50 (\u539F\u7406\u4E0A\u3001\u5404\u30CE\
    \u30FC\u30C9\u533A\u5225\u306F\u306A\u3044)\n  void update(const LInfo &l, const\
    \ LInfo &r) {}\n\n  // \u90E8\u5206\u6728\u3078\u306E\u9045\u5EF6\u4F1D\u642C\n\
    \  void propagate(const Lazy &p) {}\n};\n\n// Heavy-edge \u306E\u60C5\u5831\n\
    template< typename LInfo, typename Lazy >\nstruct Info {\n\n  // \u5358\u4F4D\u5143\
    (\u30AD\u30FC\u306E\u5024\u306F\u30A2\u30AF\u30BB\u30B9\u3057\u306A\u3044\u306E\
    \u3067\u672A\u521D\u671F\u5316\u3067\u3082\u3088\u3044\n  Info() {}\n\n  // \u521D\
    \u671F\u5316\n  Info(T v) {}\n\n  // \u53CD\u8EE2\n  void toggle() {}\n\n  //\
    \ p\u304C\u89AA, c\u304Cheavy-edge\u3067\u7D50\u3070\u308C\u305F\u5B50, l\u304C\
    \u305D\u308C\u4EE5\u5916\u306E\u5B50\n  void update(const Info &p, const Info\
    \ &c, const LInfo &l) {}\n\n  // \u89AA\u3068 light-edge \u3067\u7E4B\u3052\u308B\
    \n  LInfo link() const { return LInfo(); }\n\n  // \u9045\u5EF6\u4F1D\u642C\n\
    \  void propagate(const Lazy &p) {}\n\n  // light-edge\u306B\u5BFE\u3059\u308B\
    \u9045\u5EF6\u4F1D\u642C\n  // path\u3068subtree\u306E\u9045\u5EF6\u4F1D\u642C\
    \u304C\u4E21\u65B9\u3042\u308B\u5834\u5408\u306B\u5B9F\u88C5\u3059\u308B\n  void\
    \ propagate_light(const Lazy &p) {}\n};\n\nusing LCT = SuperLinkCutTree< Info,\
    \ LInfo, Lazy >;\n*/\n"
  code: "/**\n * @brief \u4F55\u3067\u3082\u3067\u304D\u308BLCT\n */\ntemplate < typename\
    \ LInfo, typename Lazy >\nstruct SplayTree {\n  struct Node {\n    Node *l, *r,\
    \ *p;\n    LInfo info;\n    Lazy lazy, lbuf;\n\n    explicit Node(const LInfo\
    \ &info)\n        : info(info),\n          l(nullptr),\n          r(nullptr),\n\
    \          p(nullptr),\n          lazy(Lazy()),\n          lbuf(Lazy()) {}\n \
    \ };\n\n  const LInfo e;\n\n  SplayTree(): e(LInfo()) {}\n\n  using NP = Node\
    \ *;\n\n  void rotr(NP t) {\n    NP x = t->p, y = x->p;\n    push(x), push(t);\n\
    \    if ((x->l = t->r)) t->r->p = x;\n    t->r = x, x->p = t;\n    update(x),\
    \ update(t);\n    if ((t->p = y)) {\n      if (y->l == x) y->l = t;\n      if\
    \ (y->r == x) y->r = t;\n    }\n  }\n\n  void rotl(NP t) {\n    NP x = t->p, y\
    \ = x->p;\n    push(x), push(t);\n    if ((x->r = t->l)) t->l->p = x;\n    t->l\
    \ = x, x->p = t;\n    update(x), update(t);\n    if ((t->p = y)) {\n      if (y->l\
    \ == x) y->l = t;\n      if (y->r == x) y->r = t;\n    }\n  }\n\n  const LInfo\
    \ &get_info(NP t) {\n    return t ? t->info : e;\n  }\n\n  void update(NP t) {\n\
    \    t->info.update(get_info(t->l), get_info(t->r));\n  }\n\n  NP get_right(NP\
    \ t) {\n    while (t->r) t = t->r;\n    return t;\n  }\n\n  NP alloc(const LInfo\
    \ &v) {\n    auto t = new Node(v);\n    update(t);\n    return t;\n  }\n\n  void\
    \ propagate(NP t, const Lazy &lazy) {\n    t->info.propagate(lazy);\n    t->lbuf.propagate(lazy);\n\
    \    t->lazy.propagate(lazy);\n  }\n\n  void push(NP t) {\n    if (t->l) propagate(t->l,\
    \ t->lazy);\n    if (t->r) propagate(t->r, t->lazy);\n    t->lazy = Lazy();\n\
    \  }\n\n  void splay(NP t) {\n    push(t);\n    while (t->p) {\n      NP q = t->p;\n\
    \      if (!q->p) {\n        if (q->l == t)\n          rotr(t);\n        else\n\
    \          rotl(t);\n      } else {\n        NP r = q->p;\n        if (r->l ==\
    \ q) {\n          if (q->l == t)\n            rotr(q), rotr(t);\n          else\n\
    \            rotl(t), rotr(t);\n        } else {\n          if (q->r == t)\n \
    \           rotl(q), rotl(t);\n          else\n            rotr(t), rotl(t);\n\
    \        }\n      }\n    }\n  }\n\n  NP insert(NP t, const LInfo &v) {\n    if\
    \ (not t) {\n      t = alloc(v);\n      return t;\n    } else {\n      NP cur\
    \ = get_right(t), z = alloc(v);\n      splay(cur);\n      z->p   = cur;\n    \
    \  cur->r = z;\n      update(cur);\n      splay(z);\n      return z;\n    }\n\
    \  }\n\n  NP erase(NP t) {\n    splay(t);\n    NP x = t->l, y = t->r;\n    delete\
    \ t;\n    if (not x) {\n      t = y;\n      if (t) t->p = nullptr;\n    } else\
    \ if (not y) {\n      t    = x;\n      t->p = nullptr;\n    } else {\n      x->p\
    \ = nullptr;\n      t    = get_right(x);\n      splay(t);\n      t->r = y;\n \
    \     y->p = t;\n      update(t);\n    }\n    return t;\n  }\n};\n\ntemplate <\
    \ template < typename, typename > typename _Info,\n           template < typename\
    \ > typename _LInfo, typename Lazy >\nstruct SuperLinkCutTree {\n  using LInfo\
    \ = _LInfo< Lazy >;\n  using Info  = _Info< LInfo, Lazy >;\n\n private:\n  struct\
    \ Node {\n    Node *l, *r, *p;\n    Info info;\n    typename SplayTree< LInfo,\
    \ Lazy >::Node *light, *belong;\n    bool rev;\n    Lazy hlazy, llazy;\n\n   \
    \ bool is_root() const {\n      return not p or (p->l != this and p->r != this);\n\
    \    }\n\n    explicit Node(const Info &info)\n        : info(info),\n       \
    \   l(nullptr),\n          r(nullptr),\n          p(nullptr),\n          rev(false),\n\
    \          light(nullptr),\n          belong(nullptr),\n          hlazy(Lazy()),\n\
    \          llazy(Lazy()) {}\n  };\n\n public:\n  using NP = Node *;\n  SplayTree<\
    \ LInfo, Lazy > splay_tree;\n\n private:\n  const Info e;\n\n private:\n  void\
    \ toggle(NP t) {\n    swap(t->l, t->r);\n    t->info.toggle();\n    t->rev ^=\
    \ true;\n  }\n\n  void rotr(NP t) {\n    NP x = t->p, y = x->p;\n    push(x),\
    \ push(t);\n    if ((x->l = t->r)) t->r->p = x;\n    t->r = x, x->p = t;\n   \
    \ update(x), update(t);\n    if ((t->p = y)) {\n      if (y->l == x) y->l = t;\n\
    \      if (y->r == x) y->r = t;\n    }\n  }\n\n  void rotl(NP t) {\n    NP x =\
    \ t->p, y = x->p;\n    push(x), push(t);\n    if ((x->r = t->l)) t->l->p = x;\n\
    \    t->l = x, x->p = t;\n    update(x), update(t);\n    if ((t->p = y)) {\n \
    \     if (y->l == x) y->l = t;\n      if (y->r == x) y->r = t;\n    }\n  }\n\n\
    \  void propagate_heavy(NP t, const Lazy &hlazy) {\n    t->hlazy.propagate(hlazy);\n\
    \    t->info.propagate(hlazy);\n  }\n\n  void propagate_light(NP t, const Lazy\
    \ &llazy) {\n    t->llazy.propagate(llazy);\n    t->info.propagate_light(llazy);\n\
    \  }\n\n  void propagate_all(NP t, const Lazy &lazy) {\n    propagate_heavy(t,\
    \ lazy);\n    propagate_light(t, lazy);\n  }\n\n public:\n  SuperLinkCutTree():\
    \ e{Info()}, splay_tree{} {}\n\n  void push(NP t) {\n    if (t->rev) {\n     \
    \ if (t->l) toggle(t->l);\n      if (t->r) toggle(t->r);\n      t->rev = false;\n\
    \    }\n    {\n      if (t->l) {\n        propagate_heavy(t->l, t->hlazy);\n \
    \       propagate_light(t->l, t->llazy);\n      }\n      if (t->r) {\n       \
    \ propagate_heavy(t->r, t->hlazy);\n        propagate_light(t->r, t->llazy);\n\
    \      }\n      if (t->light) {\n        splay_tree.propagate(t->light, t->llazy);\n\
    \      }\n      t->hlazy = Lazy();\n      t->llazy = Lazy();\n    }\n  }\n\n \
    \ void push_rev(NP t) {\n    if (t->rev) {\n      if (t->l) toggle(t->l);\n  \
    \    if (t->r) toggle(t->r);\n      t->rev = false;\n    }\n  }\n\n  const Info\
    \ &get_info(NP t) {\n    return t ? t->info : e;\n  }\n\n  void update(NP t) {\n\
    \    t->info.update(get_info(t->l), get_info(t->r),\n                   splay_tree.get_info(t->light));\n\
    \  }\n\n  void splay(NP t) {\n    push(t);\n    {\n      NP rot = t;\n      while\
    \ (not rot->is_root()) rot = rot->p;\n      t->belong = rot->belong;\n      if\
    \ (t != rot) rot->belong = nullptr;\n    }\n    while (not t->is_root()) {\n \
    \     NP q = t->p;\n      if (q->is_root()) {\n        push_rev(q), push_rev(t);\n\
    \        if (q->l == t)\n          rotr(t);\n        else\n          rotl(t);\n\
    \      } else {\n        NP r = q->p;\n        push_rev(r), push_rev(q), push_rev(t);\n\
    \        if (r->l == q) {\n          if (q->l == t)\n            rotr(q), rotr(t);\n\
    \          else\n            rotl(t), rotr(t);\n        } else {\n          if\
    \ (q->r == t)\n            rotl(q), rotl(t);\n          else\n            rotr(t),\
    \ rotl(t);\n        }\n      }\n    }\n  }\n\n  NP expose(NP t) {\n    NP rp =\
    \ nullptr;\n    for (NP cur = t; cur; cur = cur->p) {\n      splay(cur);\n   \
    \   if (cur->r) {\n        cur->light =\n            splay_tree.insert(cur->light,\
    \ cur->r->info.link());\n        cur->r->belong = cur->light;\n      }\n     \
    \ cur->r = rp;\n      if (cur->r) {\n        splay_tree.splay(cur->r->belong);\n\
    \        propagate_all(cur->r, cur->r->belong->lbuf);\n        push(cur->r);\n\
    \        cur->light = splay_tree.erase(cur->r->belong);\n      }\n      update(cur);\n\
    \      rp = cur;\n    }\n    splay(t);\n    return rp;\n  }\n\n  void link(NP\
    \ child, NP parent) {\n    expose(parent);\n    expose(child);\n    child->p \
    \ = parent;\n    parent->r = child;\n    update(parent);\n  }\n\n  void cut(NP\
    \ child) {\n    expose(child);\n    NP parent = child->l;\n    child->l  = nullptr;\n\
    \    parent->p = nullptr;\n    update(child);\n  }\n\n  void evert(NP t) {\n \
    \   expose(t);\n    toggle(t);\n    push(t);\n  }\n\n  NP alloc(const Info &info)\
    \ {\n    NP t = new Node(info);\n    update(t);\n    return t;\n  }\n\n  bool\
    \ is_connected(NP u, NP v) {\n    expose(u), expose(v);\n    return u == v or\
    \ u->p;\n  }\n\n  vector< NP > build(vector< Info > &vs) {\n    vector< NP > nodes(vs.size());\n\
    \    for (int i = 0; i < (int)vs.size(); i++) {\n      nodes[i] = alloc(vs[i]);\n\
    \    }\n    return nodes;\n  }\n\n  NP lca(NP u, NP v) {\n    if (not is_connected(u,\
    \ v)) return nullptr;\n    expose(u);\n    return expose(v);\n  }\n\n  void set_key(NP\
    \ t, const Info &v) {\n    expose(t);\n    t->info = move(v);\n    update(t);\n\
    \  }\n\n  void set_propagate_path(NP t, const Lazy &lazy) {\n    expose(t);\n\
    \    propagate_heavy(t, lazy);\n    push(t);\n    update(t);\n  }\n\n  void set_propagate_path(NP\
    \ u, NP v, const Lazy &lazy) {\n    evert(u);\n    set_propagate_path(v, lazy);\n\
    \  }\n\n  void set_propagate_all(NP t, const Lazy &lazy) {\n    expose(t);\n \
    \   propagate_all(t, lazy);\n    push(t);\n    update(t);\n  }\n\n  void set_propagate_subtree(NP\
    \ t, const Lazy &lazy) {\n    expose(t);\n    NP l = t->l;\n    t->l = nullptr;\n\
    \    propagate_all(t, lazy);\n    push(t);\n    t->l = l;\n    update(t);\n  }\n\
    \n  const Info &query(NP u) {\n    expose(u);\n    return get_info(u);\n  }\n\n\
    \  const Info &query_path(NP u, NP v) {\n    evert(u);\n    expose(v);\n    return\
    \ get_info(v);\n  }\n\n  Info query_subtree(NP u) {\n    expose(u);\n    NP l\
    \ = u->l;\n    u->l = nullptr;\n    update(u);\n    auto ret = u->info;\n    u->l\
    \     = l;\n    update(u);\n    return ret;\n  }\n};\n\n/*\nusing T = int64_t;\n\
    // \u9045\u5EF6\u4F1D\u642C\u3092\u3059\u308B\u305F\u3081\u306E\u4F5C\u7528\u7D20\
    \nstruct Lazy {\n\n  // \u5358\u4F4D\u5143\n  Lazy() {}\n\n  // \u521D\u671F\u5316\
    \n  Lazy(T v) {}\n\n  // \u9045\u5EF6\u4F1D\u642C\n  void propagate(const Lazy\
    \ &p) {}\n};\n\n// Light-edge \u306E\u60C5\u5831\ntemplate< typename Lazy >\n\
    struct LInfo {\n\n  // \u5358\u4F4D\u5143(\u30AD\u30FC\u306E\u5024\u306F\u30A2\
    \u30AF\u30BB\u30B9\u3057\u306A\u3044\u306E\u3067\u672A\u521D\u671F\u5316\u3067\
    \u3082\u3088\u3044\n  LInfo() {}\n\n  // \u521D\u671F\u5316\n  LInfo(T v) {}\n\
    \n  // l, r \u306F Splay-tree \u306E\u5B50 (\u539F\u7406\u4E0A\u3001\u5404\u30CE\
    \u30FC\u30C9\u533A\u5225\u306F\u306A\u3044)\n  void update(const LInfo &l, const\
    \ LInfo &r) {}\n\n  // \u90E8\u5206\u6728\u3078\u306E\u9045\u5EF6\u4F1D\u642C\n\
    \  void propagate(const Lazy &p) {}\n};\n\n// Heavy-edge \u306E\u60C5\u5831\n\
    template< typename LInfo, typename Lazy >\nstruct Info {\n\n  // \u5358\u4F4D\u5143\
    (\u30AD\u30FC\u306E\u5024\u306F\u30A2\u30AF\u30BB\u30B9\u3057\u306A\u3044\u306E\
    \u3067\u672A\u521D\u671F\u5316\u3067\u3082\u3088\u3044\n  Info() {}\n\n  // \u521D\
    \u671F\u5316\n  Info(T v) {}\n\n  // \u53CD\u8EE2\n  void toggle() {}\n\n  //\
    \ p\u304C\u89AA, c\u304Cheavy-edge\u3067\u7D50\u3070\u308C\u305F\u5B50, l\u304C\
    \u305D\u308C\u4EE5\u5916\u306E\u5B50\n  void update(const Info &p, const Info\
    \ &c, const LInfo &l) {}\n\n  // \u89AA\u3068 light-edge \u3067\u7E4B\u3052\u308B\
    \n  LInfo link() const { return LInfo(); }\n\n  // \u9045\u5EF6\u4F1D\u642C\n\
    \  void propagate(const Lazy &p) {}\n\n  // light-edge\u306B\u5BFE\u3059\u308B\
    \u9045\u5EF6\u4F1D\u642C\n  // path\u3068subtree\u306E\u9045\u5EF6\u4F1D\u642C\
    \u304C\u4E21\u65B9\u3042\u308B\u5834\u5408\u306B\u5B9F\u88C5\u3059\u308B\n  void\
    \ propagate_light(const Lazy &p) {}\n};\n\nusing LCT = SuperLinkCutTree< Info,\
    \ LInfo, Lazy >;\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/develop/super-link-cut-tree.hpp
  requiredBy:
  - structure/develop/dynamic-tree-test.hpp
  - structure/develop/diameter.hpp
  - structure/develop/vertex-set-path-composite.hpp
  - structure/develop/subtree-add-subtree-sum.hpp
  - structure/develop/vertex-set-subtree-sum.hpp
  - structure/develop/vertex-set-path-sum.hpp
  timestamp: '2022-08-27 15:55:50+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/verify/aoj-2450-4.test.cpp
  - test/verify/yosupo-dynamic-tree-subtree-add-subtree-sum.test.cpp
  - test/verify/aoj-grl-5-a-2.test.cpp
  - test/verify/dmoj-ds5.test.cpp
  - test/verify/yosupo-dynamic-tree-vertex-set-path-composite-3.test.cpp
  - test/verify/yosupo-dynamic-tree-vertex-add-subtree-sum-2.test.cpp
  - test/verify/yosupo-dynamic-tree-vertex-add-path-sum-3.test.cpp
documentation_of: structure/develop/super-link-cut-tree.hpp
layout: document
redirect_from:
- /library/structure/develop/super-link-cut-tree.hpp
- /library/structure/develop/super-link-cut-tree.hpp.html
title: "\u4F55\u3067\u3082\u3067\u304D\u308BLCT"
---
