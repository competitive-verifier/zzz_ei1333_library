---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: other/printer.cpp
    title: "Printer(\u9AD8\u901F\u51FA\u529B)"
  - icon: ':question:'
    path: other/scanner.cpp
    title: "Scanner(\u9AD8\u901F\u5165\u529B)"
  - icon: ':x:'
    path: other/static-point-add-rectangle-sum.cpp
    title: Static Point Add Rectangle Sum
  - icon: ':question:'
    path: structure/others/binary-indexed-tree.cpp
    title: Binary-Indexed-Tree(BIT)
  - icon: ':question:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_rectangle_sum
  bundledCode: "#line 1 \"test/verify/yosupo-point-add-rectangle-sum-3.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\n\n\
    #line 1 \"template/template.cpp\"\n#include<bits/stdc++.h>\n\nusing namespace\
    \ std;\n\nusing int64 = long long;\nconst int mod = 1e9 + 7;\n\nconst int64 infll\
    \ = (1LL << 62) - 1;\nconst int inf = (1 << 30) - 1;\n\nstruct IoSetup {\n  IoSetup()\
    \ {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n    cout << fixed\
    \ << setprecision(10);\n    cerr << fixed << setprecision(10);\n  }\n} iosetup;\n\
    \ntemplate< typename T1, typename T2 >\nostream &operator<<(ostream &os, const\
    \ pair< T1, T2 >& p) {\n  os << p.first << \" \" << p.second;\n  return os;\n\
    }\n\ntemplate< typename T1, typename T2 >\nistream &operator>>(istream &is, pair<\
    \ T1, T2 > &p) {\n  is >> p.first >> p.second;\n  return is;\n}\n\ntemplate< typename\
    \ T >\nostream &operator<<(ostream &os, const vector< T > &v) {\n  for(int i =\
    \ 0; i < (int) v.size(); i++) {\n    os << v[i] << (i + 1 != v.size() ? \" \"\
    \ : \"\");\n  }\n  return os;\n}\n\ntemplate< typename T >\nistream &operator>>(istream\
    \ &is, vector< T > &v) {\n  for(T &in : v) is >> in;\n  return is;\n}\n\ntemplate<\
    \ typename T1, typename T2 >\ninline bool chmax(T1 &a, T2 b) { return a < b &&\
    \ (a = b, true); }\n\ntemplate< typename T1, typename T2 >\ninline bool chmin(T1\
    \ &a, T2 b) { return a > b && (a = b, true); }\n\ntemplate< typename T = int64\
    \ >\nvector< T > make_v(size_t a) {\n  return vector< T >(a);\n}\n\ntemplate<\
    \ typename T, typename... Ts >\nauto make_v(size_t a, Ts... ts) {\n  return vector<\
    \ decltype(make_v< T >(ts...)) >(a, make_v< T >(ts...));\n}\n\ntemplate< typename\
    \ T, typename V >\ntypename enable_if< is_class< T >::value == 0 >::type fill_v(T\
    \ &t, const V &v) {\n  t = v;\n}\n\ntemplate< typename T, typename V >\ntypename\
    \ enable_if< is_class< T >::value != 0 >::type fill_v(T &t, const V &v) {\n  for(auto\
    \ &e : t) fill_v(e, v);\n}\n\ntemplate< typename F >\nstruct FixPoint : F {\n\
    \  explicit FixPoint(F &&f) : F(forward< F >(f)) {}\n\n  template< typename...\
    \ Args >\n  decltype(auto) operator()(Args &&... args) const {\n    return F::operator()(*this,\
    \ forward< Args >(args)...);\n  }\n};\n \ntemplate< typename F >\ninline decltype(auto)\
    \ MFP(F &&f) {\n  return FixPoint< F >{forward< F >(f)};\n}\n#line 4 \"test/verify/yosupo-point-add-rectangle-sum-3.test.cpp\"\
    \n\n#line 1 \"structure/others/binary-indexed-tree.cpp\"\n/**\n * @brief Binary-Indexed-Tree(BIT)\n\
    \ * @docs docs/binary-indexed-tree.md\n */\ntemplate< typename T >\nstruct BinaryIndexedTree\
    \ {\nprivate:\n  int n;\n  vector< T > data;\n\npublic:\n  BinaryIndexedTree()\
    \ = default;\n\n  explicit BinaryIndexedTree(int n) : n(n) {\n    data.assign(n\
    \ + 1, 0);\n  }\n\n  explicit BinaryIndexedTree(const vector< T > &v) :\n    \
    \  BinaryIndexedTree((int) v.size()) {\n    build(v);\n  }\n\n  void build(const\
    \ vector< T > &v) {\n    assert(n == (int) v.size());\n    for(int i = 1; i <=\
    \ n; i++) data[i] = v[i - 1];\n    for(int i = 1; i <= n; i++) {\n      int j\
    \ = i + (i & -i);\n      if(j <= n) data[j] += data[i];\n    }\n  }\n\n  void\
    \ apply(int k, const T &x) {\n    for(++k; k <= n; k += k & -k) data[k] += x;\n\
    \  }\n\n  T prod(int r) const {\n    T ret = T();\n    for(; r > 0; r -= r & -r)\
    \ ret += data[r];\n    return ret;\n  }\n\n  T prod(int l, int r) const {\n  \
    \  return prod(r) - prod(l);\n  }\n\n  int lower_bound(T x) const {\n    int i\
    \ = 0;\n    for(int k = 1 << (__lg(n) + 1); k > 0; k >>= 1) {\n      if(i + k\
    \ <= n && data[i + k] < x) {\n        x -= data[i + k];\n        i += k;\n   \
    \   }\n    }\n    return i;\n  }\n\n  int upper_bound(T x) const {\n    int i\
    \ = 0;\n    for(int k = 1 << (__lg(n) + 1); k > 0; k >>= 1) {\n      if(i + k\
    \ <= n && data[i + k] <= x) {\n        x -= data[i + k];\n        i += k;\n  \
    \    }\n    }\n    return i;\n  }\n};\n#line 2 \"other/static-point-add-rectangle-sum.cpp\"\
    \n\n/**\n * @brief Static Point Add Rectangle Sum\n */\ntemplate< typename T,\
    \ typename C >\nstruct StaticPointAddRectangleSum {\n  using BIT = BinaryIndexedTree<\
    \ C >;\n\n  static_assert(is_integral< T >::value, \"template parameter T must\
    \ be integral type\");\n\n  struct Point {\n    T x, y;\n    C w;\n  };\n\n  struct\
    \ Query {\n    T l, d, r, u;\n  };\n\n  vector< Point > points;\n  vector< Query\
    \ > queries;\n\n  StaticPointAddRectangleSum() = default;\n\n  StaticPointAddRectangleSum(int\
    \ n, int q) {\n    points.reserve(n);\n    queries.reserve(q);\n  }\n\n  void\
    \ add_point(T x, T y, C w) {\n    points.emplace_back(Point{x, y, w});\n  }\n\n\
    \  // tatal weight of [l, r) * [d, u) points\n  void add_query(T l, T d, T r,\
    \ T u) {\n    queries.emplace_back(Query{l, d, r, u});\n  }\n\n  vector< C > calculate_queries()\
    \ {\n    int n = (int) points.size();\n    int q = (int) queries.size();\n\n \
    \   sort(points.begin(), points.end(), [](const Point &a, const Point &b) {\n\
    \      return a.y < b.y;\n    });\n    vector< T > ys;\n    ys.reserve(n);\n \
    \   for(Point &p: points) {\n      if(ys.empty() or ys.back() != p.y) ys.emplace_back(p.y);\n\
    \      p.y = (int) ys.size() - 1;\n    }\n    ys.shrink_to_fit();\n\n\n    struct\
    \ Q {\n      T x, d, u;\n      bool type;\n      int idx;\n    };\n    vector<\
    \ Q > qs;\n    qs.reserve(q + q);\n    for(int i = 0; i < q; i++) {\n      auto\
    \ &query = queries[i];\n      int d = lower_bound(ys.begin(), ys.end(), query.d)\
    \ - ys.begin();\n      int u = lower_bound(ys.begin(), ys.end(), query.u) - ys.begin();\n\
    \      qs.emplace_back(Q{query.l, d, u, false, i});\n      qs.emplace_back(Q{query.r,\
    \ d, u, true, i});\n    }\n    sort(points.begin(), points.end(), [](const Point\
    \ &a, const Point &b) {\n      return a.x < b.x;\n    });\n    sort(qs.begin(),\
    \ qs.end(), [](const Q &a, const Q &b) {\n      return a.x < b.x;\n    });\n \
    \   vector< C > ans(q);\n    int j = 0;\n    BIT bit(ys.size());\n    for(auto\
    \ &query: qs) {\n      while(j < n and points[j].x < query.x) {\n        bit.apply(points[j].y,\
    \ points[j].w);\n        ++j;\n      }\n      if(query.type) ans[query.idx] +=\
    \ bit.prod(query.d, query.u);\n      else ans[query.idx] -= bit.prod(query.d,\
    \ query.u);\n    }\n    return ans;\n  }\n};\n#line 6 \"test/verify/yosupo-point-add-rectangle-sum-3.test.cpp\"\
    \n\n#line 1 \"other/scanner.cpp\"\n/**\n * @brief Scanner(\u9AD8\u901F\u5165\u529B\
    )\n */\nstruct Scanner {\npublic:\n\n  explicit Scanner(FILE *fp) : fp(fp) {}\n\
    \n  template< typename T, typename... E >\n  void read(T &t, E &... e) {\n   \
    \ read_single(t);\n    read(e...);\n  }\n\nprivate:\n  static constexpr size_t\
    \ line_size = 1 << 16;\n  static constexpr size_t int_digits = 20;\n  char line[line_size\
    \ + 1] = {};\n  FILE *fp = nullptr;\n  char *st = line;\n  char *ed = line;\n\n\
    \  void read() {}\n\n  static inline bool is_space(char c) {\n    return c <=\
    \ ' ';\n  }\n\n  void reread() {\n    ptrdiff_t len = ed - st;\n    memmove(line,\
    \ st, len);\n    char *tmp = line + len;\n    ed = tmp + fread(tmp, 1, line_size\
    \ - len, fp);\n    *ed = 0;\n    st = line;\n  }\n\n  void skip_space() {\n  \
    \  while(true) {\n      if(st == ed) reread();\n      while(*st && is_space(*st))\
    \ ++st;\n      if(st != ed) return;\n    }\n  }\n\n  template< typename T, enable_if_t<\
    \ is_integral< T >::value, int > = 0 >\n  void read_single(T &s) {\n    skip_space();\n\
    \    if(st + int_digits >= ed) reread();\n    bool neg = false;\n    if(is_signed<\
    \ T >::value && *st == '-') {\n      neg = true;\n      ++st;\n    }\n    typename\
    \ make_unsigned< T >::type y = *st++ - '0';\n    while(*st >= '0') {\n      y\
    \ = 10 * y + *st++ - '0';\n    }\n    s = (neg ? -y : y);\n  }\n\n  template<\
    \ typename T, enable_if_t< is_same< T, string >::value, int > = 0 >\n  void read_single(T\
    \ &s) {\n    s = \"\";\n    skip_space();\n    while(true) {\n      char *base\
    \ = st;\n      while(*st && !is_space(*st)) ++st;\n      s += string(base, st);\n\
    \      if(st != ed) return;\n      reread();\n    }\n  }\n\n  template< typename\
    \ T >\n  void read_single(vector< T > &s) {\n    for(auto &d : s) read(d);\n \
    \ }\n};\n#line 1 \"other/printer.cpp\"\n/**\n * @brief Printer(\u9AD8\u901F\u51FA\
    \u529B)\n */\nstruct Printer {\npublic:\n  explicit Printer(FILE *fp) : fp(fp)\
    \ {}\n\n  ~Printer() { flush(); }\n\n  template< bool f = false, typename T, typename...\
    \ E >\n  void write(const T &t, const E &... e) {\n    if(f) write_single(' ');\n\
    \    write_single(t);\n    write< true >(e...);\n  }\n\n  template< typename...\
    \ T >\n  void writeln(const T &...t) {\n    write(t...);\n    write_single('\\\
    n');\n  }\n\n  void flush() {\n    fwrite(line, 1, st - line, fp);\n    st = line;\n\
    \  }\n\nprivate:\n  FILE *fp = nullptr;\n  static constexpr size_t line_size =\
    \ 1 << 16;\n  static constexpr size_t int_digits = 20;\n  char line[line_size\
    \ + 1] = {};\n  char *st = line;\n\n  template< bool f = false >\n  void write()\
    \ {}\n\n  void write_single(const char &t) {\n    if(st + 1 >= line + line_size)\
    \ flush();\n    *st++ = t;\n  }\n\n  template< typename T, enable_if_t< is_integral<\
    \ T >::value, int > = 0 >\n  void write_single(T s) {\n    if(st + int_digits\
    \ >= line + line_size) flush();\n    st += to_chars(st, st + int_digits, s).ptr\
    \ - st;\n  }\n\n  void write_single(const string &s) {\n    for(auto &c: s) write_single(c);\n\
    \  }\n\n  void write_single(const char *s) {\n    while(*s != 0) write_single(*s++);\n\
    \  }\n\n  template< typename T >\n  void write_single(const vector< T > &s) {\n\
    \    for(size_t i = 0; i < s.size(); i++) {\n      if(i) write_single(' ');\n\
    \      write_single(s[i]);\n    }\n  }\n};\n#line 9 \"test/verify/yosupo-point-add-rectangle-sum-3.test.cpp\"\
    \n\nint main() {\n  int N, Q;\n  Scanner in(stdin);\n  Printer out(stdout);\n\
    \  in.read(N, Q);\n  StaticPointAddRectangleSum< int, int64 > spars;\n  for(int\
    \ i = 0; i < N; i++) {\n    int x, y, z;\n    in.read(x, y, z);\n    spars.add_point(x,\
    \ y, z);\n  }\n  vector< tuple< int, int, int, int > > query;\n  query.reserve(Q);\n\
    \  for(int i = 0; i < Q; i++) {\n    int l, d, r, u;\n    in.read(l, d, r, u);\n\
    \    spars.add_query(l, d, r, u);\n  }\n  for(auto &&ans: spars.calculate_queries())\
    \ {\n    out.writeln(ans);\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \n\n#include \"../../template/template.cpp\"\n\n#include \"../../other/static-point-add-rectangle-sum.cpp\"\
    \n\n#include \"../../other/scanner.cpp\"\n#include \"../../other/printer.cpp\"\
    \n\nint main() {\n  int N, Q;\n  Scanner in(stdin);\n  Printer out(stdout);\n\
    \  in.read(N, Q);\n  StaticPointAddRectangleSum< int, int64 > spars;\n  for(int\
    \ i = 0; i < N; i++) {\n    int x, y, z;\n    in.read(x, y, z);\n    spars.add_point(x,\
    \ y, z);\n  }\n  vector< tuple< int, int, int, int > > query;\n  query.reserve(Q);\n\
    \  for(int i = 0; i < Q; i++) {\n    int l, d, r, u;\n    in.read(l, d, r, u);\n\
    \    spars.add_query(l, d, r, u);\n  }\n  for(auto &&ans: spars.calculate_queries())\
    \ {\n    out.writeln(ans);\n  }\n}\n"
  dependsOn:
  - template/template.cpp
  - other/static-point-add-rectangle-sum.cpp
  - structure/others/binary-indexed-tree.cpp
  - other/scanner.cpp
  - other/printer.cpp
  isVerificationFile: true
  path: test/verify/yosupo-point-add-rectangle-sum-3.test.cpp
  requiredBy: []
  timestamp: '2022-06-12 20:13:41+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/verify/yosupo-point-add-rectangle-sum-3.test.cpp
layout: document
redirect_from:
- /verify/test/verify/yosupo-point-add-rectangle-sum-3.test.cpp
- /verify/test/verify/yosupo-point-add-rectangle-sum-3.test.cpp.html
title: test/verify/yosupo-point-add-rectangle-sum-3.test.cpp
---
