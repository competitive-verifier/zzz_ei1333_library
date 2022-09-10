---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/graph-template.hpp
    title: "Graph Template(\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/verify/aoj-grl-1-a-3.test.cpp
    title: test/verify/aoj-grl-1-a-3.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "Dijkstra-Radix-Heap(\u5358\u4E00\u59CB\u70B9\u6700\u77ED\u8DEF\
      )"
    links: []
  bundledCode: "#line 2 \"graph/shortest-path/dijkstra-radix-heap.hpp\"\n\n#line 2\
    \ \"graph/graph-template.hpp\"\n\n/**\n * @brief Graph Template(\u30B0\u30E9\u30D5\
    \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)\n */\ntemplate< typename T = int >\nstruct\
    \ Edge {\n  int from, to;\n  T cost;\n  int idx;\n\n  Edge() = default;\n\n  Edge(int\
    \ from, int to, T cost = 1, int idx = -1) : from(from), to(to), cost(cost), idx(idx)\
    \ {}\n\n  operator int() const { return to; }\n};\n\ntemplate< typename T = int\
    \ >\nstruct Graph {\n  vector< vector< Edge< T > > > g;\n  int es;\n\n  Graph()\
    \ = default;\n\n  explicit Graph(int n) : g(n), es(0) {}\n\n  size_t size() const\
    \ {\n    return g.size();\n  }\n\n  void add_directed_edge(int from, int to, T\
    \ cost = 1) {\n    g[from].emplace_back(from, to, cost, es++);\n  }\n\n  void\
    \ add_edge(int from, int to, T cost = 1) {\n    g[from].emplace_back(from, to,\
    \ cost, es);\n    g[to].emplace_back(to, from, cost, es++);\n  }\n\n  void read(int\
    \ M, int padding = -1, bool weighted = false, bool directed = false) {\n    for(int\
    \ i = 0; i < M; i++) {\n      int a, b;\n      cin >> a >> b;\n      a += padding;\n\
    \      b += padding;\n      T c = T(1);\n      if(weighted) cin >> c;\n      if(directed)\
    \ add_directed_edge(a, b, c);\n      else add_edge(a, b, c);\n    }\n  }\n\n \
    \ inline vector< Edge< T > > &operator[](const int &k) {\n    return g[k];\n \
    \ }\n\n  inline const vector< Edge< T > > &operator[](const int &k) const {\n\
    \    return g[k];\n  }\n};\n\ntemplate< typename T = int >\nusing Edges = vector<\
    \ Edge< T > >;\n#line 4 \"graph/shortest-path/dijkstra-radix-heap.hpp\"\n\n/**\n\
    \ * @brief Dijkstra-Radix-Heap(\u5358\u4E00\u59CB\u70B9\u6700\u77ED\u8DEF)\n */\n\
    template< typename T >\nvector< T > dijkstra_radix_heap(Graph< T > &g, int s)\
    \ {\n  const auto INF = numeric_limits< T >::max();\n  vector< T > dist(g.size(),\
    \ INF);\n\n  RadixHeap< T, int > heap;\n  dist[s] = 0;\n  heap.push(dist[s], s);\n\
    \  while(!heap.empty()) {\n    T cost;\n    int idx;\n    tie(cost, idx) = heap.pop();\n\
    \    if(dist[idx] < cost) continue;\n    for(auto &e : g.g[idx]) {\n      auto\
    \ next_cost = cost + e.cost;\n      if(dist[e.to] <= next_cost) continue;\n  \
    \    dist[e.to] = next_cost;\n      heap.push(dist[e.to], e.to);\n    }\n  }\n\
    \  return dist;\n}\n"
  code: "#pragma once\n\n#include \"../graph-template.hpp\"\n\n/**\n * @brief Dijkstra-Radix-Heap(\u5358\
    \u4E00\u59CB\u70B9\u6700\u77ED\u8DEF)\n */\ntemplate< typename T >\nvector< T\
    \ > dijkstra_radix_heap(Graph< T > &g, int s) {\n  const auto INF = numeric_limits<\
    \ T >::max();\n  vector< T > dist(g.size(), INF);\n\n  RadixHeap< T, int > heap;\n\
    \  dist[s] = 0;\n  heap.push(dist[s], s);\n  while(!heap.empty()) {\n    T cost;\n\
    \    int idx;\n    tie(cost, idx) = heap.pop();\n    if(dist[idx] < cost) continue;\n\
    \    for(auto &e : g.g[idx]) {\n      auto next_cost = cost + e.cost;\n      if(dist[e.to]\
    \ <= next_cost) continue;\n      dist[e.to] = next_cost;\n      heap.push(dist[e.to],\
    \ e.to);\n    }\n  }\n  return dist;\n}\n"
  dependsOn:
  - graph/graph-template.hpp
  isVerificationFile: false
  path: graph/shortest-path/dijkstra-radix-heap.hpp
  requiredBy: []
  timestamp: '2022-09-11 00:53:50+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/verify/aoj-grl-1-a-3.test.cpp
documentation_of: graph/shortest-path/dijkstra-radix-heap.hpp
layout: document
redirect_from:
- /library/graph/shortest-path/dijkstra-radix-heap.hpp
- /library/graph/shortest-path/dijkstra-radix-heap.hpp.html
title: "Dijkstra-Radix-Heap(\u5358\u4E00\u59CB\u70B9\u6700\u77ED\u8DEF)"
---
