---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/graph-template.hpp
    title: "Graph Template(\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)"
  - icon: ':heavy_check_mark:'
    path: graph/mst/kruskal.hpp
    title: "Kruskal(\u6700\u5C0F\u5168\u57DF\u6728)"
  - icon: ':heavy_check_mark:'
    path: graph/mst/manhattan-mst.hpp
    title: Manhattan MST
  - icon: ':question:'
    path: structure/union-find/union-find.hpp
    title: Union Find
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/manhattanmst
    links:
    - https://judge.yosupo.jp/problem/manhattanmst
  bundledCode: "#line 1 \"test/verify/yosupo-manhattanmst.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/manhattanmst\"\n\n#line 1 \"template/template.hpp\"\
    \n#include<bits/stdc++.h>\n\nusing namespace std;\n\nusing int64 = long long;\n\
    const int mod = 1e9 + 7;\n\nconst int64 infll = (1LL << 62) - 1;\nconst int inf\
    \ = (1 << 30) - 1;\n\nstruct IoSetup {\n  IoSetup() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n    cout << fixed << setprecision(10);\n  \
    \  cerr << fixed << setprecision(10);\n  }\n} iosetup;\n\ntemplate< typename T1,\
    \ typename T2 >\nostream &operator<<(ostream &os, const pair< T1, T2 >& p) {\n\
    \  os << p.first << \" \" << p.second;\n  return os;\n}\n\ntemplate< typename\
    \ T1, typename T2 >\nistream &operator>>(istream &is, pair< T1, T2 > &p) {\n \
    \ is >> p.first >> p.second;\n  return is;\n}\n\ntemplate< typename T >\nostream\
    \ &operator<<(ostream &os, const vector< T > &v) {\n  for(int i = 0; i < (int)\
    \ v.size(); i++) {\n    os << v[i] << (i + 1 != v.size() ? \" \" : \"\");\n  }\n\
    \  return os;\n}\n\ntemplate< typename T >\nistream &operator>>(istream &is, vector<\
    \ T > &v) {\n  for(T &in : v) is >> in;\n  return is;\n}\n\ntemplate< typename\
    \ T1, typename T2 >\ninline bool chmax(T1 &a, T2 b) { return a < b && (a = b,\
    \ true); }\n\ntemplate< typename T1, typename T2 >\ninline bool chmin(T1 &a, T2\
    \ b) { return a > b && (a = b, true); }\n\ntemplate< typename T = int64 >\nvector<\
    \ T > make_v(size_t a) {\n  return vector< T >(a);\n}\n\ntemplate< typename T,\
    \ typename... Ts >\nauto make_v(size_t a, Ts... ts) {\n  return vector< decltype(make_v<\
    \ T >(ts...)) >(a, make_v< T >(ts...));\n}\n\ntemplate< typename T, typename V\
    \ >\ntypename enable_if< is_class< T >::value == 0 >::type fill_v(T &t, const\
    \ V &v) {\n  t = v;\n}\n\ntemplate< typename T, typename V >\ntypename enable_if<\
    \ is_class< T >::value != 0 >::type fill_v(T &t, const V &v) {\n  for(auto &e\
    \ : t) fill_v(e, v);\n}\n\ntemplate< typename F >\nstruct FixPoint : F {\n  explicit\
    \ FixPoint(F &&f) : F(forward< F >(f)) {}\n\n  template< typename... Args >\n\
    \  decltype(auto) operator()(Args &&... args) const {\n    return F::operator()(*this,\
    \ forward< Args >(args)...);\n  }\n};\n \ntemplate< typename F >\ninline decltype(auto)\
    \ MFP(F &&f) {\n  return FixPoint< F >{forward< F >(f)};\n}\n#line 4 \"test/verify/yosupo-manhattanmst.test.cpp\"\
    \n\n#line 2 \"graph/mst/manhattan-mst.hpp\"\n\n#line 2 \"graph/graph-template.hpp\"\
    \n\n/**\n * @brief Graph Template(\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\
    \u30C8)\n */\ntemplate< typename T = int >\nstruct Edge {\n  int from, to;\n \
    \ T cost;\n  int idx;\n\n  Edge() = default;\n\n  Edge(int from, int to, T cost\
    \ = 1, int idx = -1) : from(from), to(to), cost(cost), idx(idx) {}\n\n  operator\
    \ int() const { return to; }\n};\n\ntemplate< typename T = int >\nstruct Graph\
    \ {\n  vector< vector< Edge< T > > > g;\n  int es;\n\n  Graph() = default;\n\n\
    \  explicit Graph(int n) : g(n), es(0) {}\n\n  size_t size() const {\n    return\
    \ g.size();\n  }\n\n  void add_directed_edge(int from, int to, T cost = 1) {\n\
    \    g[from].emplace_back(from, to, cost, es++);\n  }\n\n  void add_edge(int from,\
    \ int to, T cost = 1) {\n    g[from].emplace_back(from, to, cost, es);\n    g[to].emplace_back(to,\
    \ from, cost, es++);\n  }\n\n  void read(int M, int padding = -1, bool weighted\
    \ = false, bool directed = false) {\n    for(int i = 0; i < M; i++) {\n      int\
    \ a, b;\n      cin >> a >> b;\n      a += padding;\n      b += padding;\n    \
    \  T c = T(1);\n      if(weighted) cin >> c;\n      if(directed) add_directed_edge(a,\
    \ b, c);\n      else add_edge(a, b, c);\n    }\n  }\n\n  inline vector< Edge<\
    \ T > > &operator[](const int &k) {\n    return g[k];\n  }\n\n  inline const vector<\
    \ Edge< T > > &operator[](const int &k) const {\n    return g[k];\n  }\n};\n\n\
    template< typename T = int >\nusing Edges = vector< Edge< T > >;\n#line 4 \"graph/mst/manhattan-mst.hpp\"\
    \n\n/**\n * @brief Manhattan MST\n */\ntemplate< typename T >\nEdges< T > manhattan_mst(vector<\
    \ T > xs, vector< T > ys) {\n  assert(xs.size() == ys.size());\n  Edges< T > ret;\n\
    \  int n = (int) xs.size();\n\n  vector< int > ord(n);\n  iota(ord.begin(), ord.end(),\
    \ 0);\n\n  for(int s = 0; s < 2; s++) {\n    for(int t = 0; t < 2; t++) {\n  \
    \    auto cmp = [&](int i, int j) -> bool {\n        return xs[i] + ys[i] < xs[j]\
    \ + ys[j];\n      };\n      sort(ord.begin(), ord.end(), cmp);\n\n      map< T,\
    \ int > idx;\n      for(int i:ord) {\n        for(auto it = idx.lower_bound(-ys[i]);\n\
    \            it != idx.end(); it = idx.erase(it)) {\n          int j = it->second;\n\
    \          if(xs[i] - xs[j] < ys[i] - ys[j]) break;\n          ret.emplace_back(i,\
    \ j, abs(xs[i] - xs[j]) + abs(ys[i] - ys[j]));\n        }\n        idx[-ys[i]]\
    \ = i;\n      }\n      swap(xs, ys);\n    }\n    for(int i = 0; i < n; i++) xs[i]\
    \ *= -1;\n  }\n  return ret;\n}\n#line 2 \"graph/mst/kruskal.hpp\"\n\n#line 2\
    \ \"structure/union-find/union-find.hpp\"\n\nstruct UnionFind {\n  vector< int\
    \ > data;\n\n  UnionFind() = default;\n\n  explicit UnionFind(size_t sz) : data(sz,\
    \ -1) {}\n\n  bool unite(int x, int y) {\n    x = find(x), y = find(y);\n    if(x\
    \ == y) return false;\n    if(data[x] > data[y]) swap(x, y);\n    data[x] += data[y];\n\
    \    data[y] = x;\n    return true;\n  }\n\n  int find(int k) {\n    if(data[k]\
    \ < 0) return (k);\n    return data[k] = find(data[k]);\n  }\n\n  int size(int\
    \ k) {\n    return -data[find(k)];\n  }\n\n  bool same(int x, int y) {\n    return\
    \ find(x) == find(y);\n  }\n\n  vector< vector< int > > groups() {\n    int n\
    \ = (int) data.size();\n    vector< vector< int > > ret(n);\n    for(int i = 0;\
    \ i < n; i++) {\n      ret[find(i)].emplace_back(i);\n    }\n    ret.erase(remove_if(begin(ret),\
    \ end(ret), [&](const vector< int > &v) {\n      return v.empty();\n    }), end(ret));\n\
    \    return ret;\n  }\n};\n#line 5 \"graph/mst/kruskal.hpp\"\n\n/**\n * @brief\
    \ Kruskal(\u6700\u5C0F\u5168\u57DF\u6728)\n * @docs docs/kruskal.md\n */\ntemplate<\
    \ typename T >\nstruct MinimumSpanningTree {\n  T cost;\n  Edges< T > edges;\n\
    };\n\ntemplate< typename T >\nMinimumSpanningTree< T > kruskal(Edges< T > &edges,\
    \ int V) {\n  sort(begin(edges), end(edges), [](const Edge< T > &a, const Edge<\
    \ T > &b) {\n    return a.cost < b.cost;\n  });\n  UnionFind tree(V);\n  T total\
    \ = T();\n  Edges< T > es;\n  for(auto &e : edges) {\n    if(tree.unite(e.from,\
    \ e.to)) {\n      es.emplace_back(e);\n      total += e.cost;\n    }\n  }\n  return\
    \ {total, es};\n}\n#line 7 \"test/verify/yosupo-manhattanmst.test.cpp\"\n\nint\
    \ main() {\n  int N;\n  cin >> N;\n  vector< int64_t > X(N), Y(N);\n  for(int\
    \ i = 0; i < N; i++) {\n    cin >> X[i] >> Y[i];\n  }\n  auto es = manhattan_mst(X,\
    \ Y);\n  auto ret = kruskal(es, N);\n  cout << ret.cost << \"\\n\";\n  for(auto\
    \ &e : ret.edges) cout << e.from << \" \" << e.to << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/manhattanmst\"\n\n#include\
    \ \"../../template/template.hpp\"\n\n#include \"../../graph/mst/manhattan-mst.hpp\"\
    \n#include \"../../graph/mst/kruskal.hpp\"\n\nint main() {\n  int N;\n  cin >>\
    \ N;\n  vector< int64_t > X(N), Y(N);\n  for(int i = 0; i < N; i++) {\n    cin\
    \ >> X[i] >> Y[i];\n  }\n  auto es = manhattan_mst(X, Y);\n  auto ret = kruskal(es,\
    \ N);\n  cout << ret.cost << \"\\n\";\n  for(auto &e : ret.edges) cout << e.from\
    \ << \" \" << e.to << \"\\n\";\n}\n"
  dependsOn:
  - template/template.hpp
  - graph/mst/manhattan-mst.hpp
  - graph/graph-template.hpp
  - graph/mst/kruskal.hpp
  - structure/union-find/union-find.hpp
  isVerificationFile: true
  path: test/verify/yosupo-manhattanmst.test.cpp
  requiredBy: []
  timestamp: '2022-10-23 21:54:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/yosupo-manhattanmst.test.cpp
layout: document
redirect_from:
- /verify/test/verify/yosupo-manhattanmst.test.cpp
- /verify/test/verify/yosupo-manhattanmst.test.cpp.html
title: test/verify/yosupo-manhattanmst.test.cpp
---
