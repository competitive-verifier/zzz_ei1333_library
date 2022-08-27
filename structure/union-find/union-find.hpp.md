---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: graph/connected-components/incremental-bridge-connectivity.hpp
    title: Incremental Bridge Connectivity
  - icon: ':x:'
    path: graph/connected-components/three-edge-connected-components.hpp
    title: graph/connected-components/three-edge-connected-components.hpp
  - icon: ':warning:'
    path: graph/flow/burn-bury.hpp
    title: "Burn Bury(\u71C3\u3084\u3059\u57CB\u3081\u308B)"
  - icon: ':x:'
    path: graph/mst/boruvka.hpp
    title: "Boruvka(\u6700\u5C0F\u5168\u57DF\u6728)"
  - icon: ':x:'
    path: graph/mst/kruskal.hpp
    title: "Kruskal(\u6700\u5C0F\u5168\u57DF\u6728)"
  - icon: ':x:'
    path: graph/others/bipartite-graph-edge-coloring.hpp
    title: "Bipartite Graph Edge Coloring(\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u8FBA\
      \u5F69\u8272)"
  - icon: ':x:'
    path: graph/others/eulerian-trail.hpp
    title: "Eulerian Trail(\u30AA\u30A4\u30E9\u30FC\u8DEF)"
  - icon: ':x:'
    path: graph/tree/offline-lca.hpp
    title: "Offline LCA(\u30AA\u30D5\u30E9\u30A4\u30F3\u6700\u5C0F\u5171\u901A\u7956\
      \u5148)"
  - icon: ':x:'
    path: other/mo-tree.hpp
    title: "Mo Tree(\u6728\u4E0A\u306EMo)"
  - icon: ':x:'
    path: other/offline-rmq.hpp
    title: Offline RMQ
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/verify/aoj-2270.test.cpp
    title: test/verify/aoj-2270.test.cpp
  - icon: ':x:'
    path: test/verify/aoj-2821.test.cpp
    title: test/verify/aoj-2821.test.cpp
  - icon: ':x:'
    path: test/verify/aoj-3139.test.cpp
    title: test/verify/aoj-3139.test.cpp
  - icon: ':x:'
    path: test/verify/aoj-dsl-1-a.test.cpp
    title: test/verify/aoj-dsl-1-a.test.cpp
  - icon: ':x:'
    path: test/verify/aoj-grl-2-a-2.test.cpp
    title: test/verify/aoj-grl-2-a-2.test.cpp
  - icon: ':x:'
    path: test/verify/aoj-grl-2-a-3.test.cpp
    title: test/verify/aoj-grl-2-a-3.test.cpp
  - icon: ':x:'
    path: test/verify/yosupo-bipartite-edge-coloring.test.cpp
    title: test/verify/yosupo-bipartite-edge-coloring.test.cpp
  - icon: ':x:'
    path: test/verify/yosupo-lca-4.test.cpp
    title: test/verify/yosupo-lca-4.test.cpp
  - icon: ':x:'
    path: test/verify/yosupo-manhattanmst.test.cpp
    title: test/verify/yosupo-manhattanmst.test.cpp
  - icon: ':x:'
    path: test/verify/yosupo-staticrmq-6.test.cpp
    title: test/verify/yosupo-staticrmq-6.test.cpp
  - icon: ':x:'
    path: test/verify/yosupo-three-edge-connected-components.test.cpp
    title: test/verify/yosupo-three-edge-connected-components.test.cpp
  - icon: ':x:'
    path: test/verify/yosupo-tree-decomposition-width-2.test.cpp
    title: test/verify/yosupo-tree-decomposition-width-2.test.cpp
  - icon: ':x:'
    path: test/verify/yosupo-two-edge-connected-components-2.test.cpp
    title: test/verify/yosupo-two-edge-connected-components-2.test.cpp
  - icon: ':x:'
    path: test/verify/yukicoder-583.test.cpp
    title: test/verify/yukicoder-583.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/union-find.md
    document_title: Union-Find
    links: []
  bundledCode: "#line 2 \"structure/union-find/union-find.hpp\"\n\n/**\n * @brief\
    \ Union-Find\n * @docs docs/union-find.md\n */\nstruct UnionFind {\n  vector<\
    \ int > data;\n\n  UnionFind() = default;\n\n  explicit UnionFind(size_t sz):\
    \ data(sz, -1) {}\n\n  bool unite(int x, int y) {\n    x = find(x), y = find(y);\n\
    \    if (x == y) return false;\n    if (data[x] > data[y]) swap(x, y);\n    data[x]\
    \ += data[y];\n    data[y] = x;\n    return true;\n  }\n\n  int find(int k) {\n\
    \    if (data[k] < 0) return (k);\n    return data[k] = find(data[k]);\n  }\n\n\
    \  int size(int k) {\n    return -data[find(k)];\n  }\n\n  bool same(int x, int\
    \ y) {\n    return find(x) == find(y);\n  }\n\n  vector< vector< int > > groups()\
    \ {\n    int n = (int)data.size();\n    vector< vector< int > > ret(n);\n    for\
    \ (int i = 0; i < n; i++) {\n      ret[find(i)].emplace_back(i);\n    }\n    ret.erase(\n\
    \        remove_if(begin(ret), end(ret),\n                  [&](const vector<\
    \ int > &v) { return v.empty(); }),\n        end(ret));\n    return ret;\n  }\n\
    };\n"
  code: "#pragma once\n\n/**\n * @brief Union-Find\n * @docs docs/union-find.md\n\
    \ */\nstruct UnionFind {\n  vector< int > data;\n\n  UnionFind() = default;\n\n\
    \  explicit UnionFind(size_t sz): data(sz, -1) {}\n\n  bool unite(int x, int y)\
    \ {\n    x = find(x), y = find(y);\n    if (x == y) return false;\n    if (data[x]\
    \ > data[y]) swap(x, y);\n    data[x] += data[y];\n    data[y] = x;\n    return\
    \ true;\n  }\n\n  int find(int k) {\n    if (data[k] < 0) return (k);\n    return\
    \ data[k] = find(data[k]);\n  }\n\n  int size(int k) {\n    return -data[find(k)];\n\
    \  }\n\n  bool same(int x, int y) {\n    return find(x) == find(y);\n  }\n\n \
    \ vector< vector< int > > groups() {\n    int n = (int)data.size();\n    vector<\
    \ vector< int > > ret(n);\n    for (int i = 0; i < n; i++) {\n      ret[find(i)].emplace_back(i);\n\
    \    }\n    ret.erase(\n        remove_if(begin(ret), end(ret),\n            \
    \      [&](const vector< int > &v) { return v.empty(); }),\n        end(ret));\n\
    \    return ret;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/union-find/union-find.hpp
  requiredBy:
  - graph/tree/offline-lca.hpp
  - graph/others/eulerian-trail.hpp
  - graph/others/bipartite-graph-edge-coloring.hpp
  - graph/mst/kruskal.hpp
  - graph/mst/boruvka.hpp
  - graph/connected-components/three-edge-connected-components.hpp
  - graph/connected-components/incremental-bridge-connectivity.hpp
  - graph/flow/burn-bury.hpp
  - other/mo-tree.hpp
  - other/offline-rmq.hpp
  timestamp: '2022-08-27 15:55:50+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/verify/aoj-grl-2-a-2.test.cpp
  - test/verify/yosupo-bipartite-edge-coloring.test.cpp
  - test/verify/aoj-dsl-1-a.test.cpp
  - test/verify/yosupo-tree-decomposition-width-2.test.cpp
  - test/verify/yosupo-manhattanmst.test.cpp
  - test/verify/yosupo-staticrmq-6.test.cpp
  - test/verify/aoj-grl-2-a-3.test.cpp
  - test/verify/yosupo-two-edge-connected-components-2.test.cpp
  - test/verify/yukicoder-583.test.cpp
  - test/verify/yosupo-lca-4.test.cpp
  - test/verify/aoj-2821.test.cpp
  - test/verify/aoj-3139.test.cpp
  - test/verify/yosupo-three-edge-connected-components.test.cpp
  - test/verify/aoj-2270.test.cpp
documentation_of: structure/union-find/union-find.hpp
layout: document
redirect_from:
- /library/structure/union-find/union-find.hpp
- /library/structure/union-find/union-find.hpp.html
title: Union-Find
---
## 概要

集合を高速に扱うためのデータ構造. 集合を合併する操作(unite), ある要素がどの集合に属しているか(find) を問い合わせる操作を行うことが出来る.

* `unite(x, y)`: 集合 `x` と `y` を併合する. 併合済のとき `false`, 未併合のとき `true` が返される.
* `find(k)`: 要素 `k` が属する集合を求める.
* `size(k)`: 要素 `k` が属する集合の要素の数を求める.
* `same(x, y)`: 要素 `x`, `y` が同じ集合に属するか判定する.
* `groups()`: 各集合に含まれる要素を返す.

## 計算量

* クエリ: ならし $O(\alpha(N))$ ($\alpha$ はアッカーマンの逆関数) 
