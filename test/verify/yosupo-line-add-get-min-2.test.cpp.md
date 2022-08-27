---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: structure/convex-hull-trick/convex-hull-trick-add-monotone.hpp
    title: Convex Hull Trick Add Monotone
  - icon: ':x:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/line_add_get_min
    links:
    - https://judge.yosupo.jp/problem/line_add_get_min
  bundledCode: "#line 1 \"test/verify/yosupo-line-add-get-min-2.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n#line 1 \"structure/convex-hull-trick/convex-hull-trick-add-monotone.hpp\"\
    \n/**\n * @brief Convex Hull Trick Add Monotone\n * @docs docs/convex-hull-trick-add-monotone.md\n\
    */\ntemplate < typename T, bool isMin >\nstruct ConvexHullTrickAddMonotone {\n\
    #define F first\n#define S second\n  using P = pair< T, T >;\n  deque< P > H;\n\
    \n  ConvexHullTrickAddMonotone() = default;\n\n  bool empty() const {\n    return\
    \ H.empty();\n  }\n\n  void clear() {\n    H.clear();\n  }\n\n  inline int sgn(T\
    \ x) {\n    return x == 0 ? 0 : (x < 0 ? -1 : 1);\n  }\n\n  inline bool check(const\
    \ P &a, const P &b, const P &c) {\n    if (b.S == a.S || c.S == b.S)\n      return\
    \ sgn(b.F - a.F) * sgn(c.S - b.S) >=\n          sgn(c.F - b.F) * sgn(b.S - a.S);\n\
    \    //return (b.F-a.F)*(c.S-b.S) >= (b.S-a.S)*(c.F-b.F);\n    if (is_integral<\
    \ T >::value) {\n      return (b.S - a.S) / (a.F - b.F) >= (c.S - b.S) / (b.F\
    \ - c.F);\n    } else {\n      return (b.F - a.F) * sgn(c.S - b.S) / abs(b.S -\
    \ a.S) >=\n          (c.F - b.F) * sgn(b.S - a.S) / abs(c.S - b.S);\n    }\n \
    \ }\n\n  void add(T a, T b) {\n    if (!isMin) a *= -1, b *= -1;\n    P line(a,\
    \ b);\n    if (empty()) {\n      H.emplace_front(line);\n      return;\n    }\n\
    \    if (H.front().F <= a) {\n      if (H.front().F == a) {\n        if (H.front().S\
    \ <= b) return;\n        H.pop_front();\n      }\n      while (H.size() >= 2 &&\
    \ check(line, H.front(), H[1]))\n        H.pop_front();\n      H.emplace_front(line);\n\
    \    } else {\n      assert(a <= H.back().F);\n      if (H.back().F == a) {\n\
    \        if (H.back().S <= b) return;\n        H.pop_back();\n      }\n      while\
    \ (H.size() >= 2 && check(H[H.size() - 2], H.back(), line))\n        H.pop_back();\n\
    \      H.emplace_back(line);\n    }\n  }\n\n  inline T get_y(const P &a, const\
    \ T &x) {\n    return a.F * x + a.S;\n  }\n\n  T query(T x) {\n    assert(!empty());\n\
    \    int l = -1, r = H.size() - 1;\n    while (l + 1 < r) {\n      int m = (l\
    \ + r) >> 1;\n      if (get_y(H[m], x) >= get_y(H[m + 1], x))\n        l = m;\n\
    \      else\n        r = m;\n    }\n    if (isMin) return get_y(H[r], x);\n  \
    \  return -get_y(H[r], x);\n  }\n\n  T query_monotone_inc(T x) {\n    assert(!empty());\n\
    \    while (H.size() >= 2 && get_y(H.front(), x) >= get_y(H[1], x))\n      H.pop_front();\n\
    \    if (isMin) return get_y(H.front(), x);\n    return -get_y(H.front(), x);\n\
    \  }\n\n  T query_monotone_dec(T x) {\n    assert(!empty());\n    while (H.size()\
    \ >= 2 &&\n           get_y(H.back(), x) >= get_y(H[H.size() - 2], x))\n     \
    \ H.pop_back();\n    if (isMin) return get_y(H.back(), x);\n    return -get_y(H.back(),\
    \ x);\n  }\n\n#undef F\n#undef S\n};\n#line 1 \"template/template.hpp\"\n#include\
    \ <bits/stdc++.h>\n\nusing namespace std;\n\nusing int64   = long long;\nconst\
    \ int mod = 1e9 + 7;\n\nconst int64 infll = (1LL << 62) - 1;\nconst int inf  \
    \   = (1 << 30) - 1;\n\nstruct IoSetup {\n  IoSetup() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n    cout << fixed << setprecision(10);\n  \
    \  cerr << fixed << setprecision(10);\n  }\n} iosetup;\n\ntemplate < typename\
    \ T1, typename T2 >\nostream &operator<<(ostream &os, const pair< T1, T2 > &p)\
    \ {\n  os << p.first << \" \" << p.second;\n  return os;\n}\n\ntemplate < typename\
    \ T1, typename T2 >\nistream &operator>>(istream &is, pair< T1, T2 > &p) {\n \
    \ is >> p.first >> p.second;\n  return is;\n}\n\ntemplate < typename T >\nostream\
    \ &operator<<(ostream &os, const vector< T > &v) {\n  for (int i = 0; i < (int)v.size();\
    \ i++) {\n    os << v[i] << (i + 1 != v.size() ? \" \" : \"\");\n  }\n  return\
    \ os;\n}\n\ntemplate < typename T >\nistream &operator>>(istream &is, vector<\
    \ T > &v) {\n  for (T &in: v) is >> in;\n  return is;\n}\n\ntemplate < typename\
    \ T1, typename T2 >\ninline bool chmax(T1 &a, T2 b) {\n  return a < b && (a =\
    \ b, true);\n}\n\ntemplate < typename T1, typename T2 >\ninline bool chmin(T1\
    \ &a, T2 b) {\n  return a > b && (a = b, true);\n}\n\ntemplate < typename T =\
    \ int64 >\nvector< T > make_v(size_t a) {\n  return vector< T >(a);\n}\n\ntemplate\
    \ < typename T, typename... Ts >\nauto make_v(size_t a, Ts... ts) {\n  return\
    \ vector< decltype(make_v< T >(ts...)) >(a,\n                                \
    \                make_v< T >(ts...));\n}\n\ntemplate < typename T, typename V\
    \ >\ntypename enable_if< is_class< T >::value == 0 >::type fill_v(\n    T &t,\
    \ const V &v) {\n  t = v;\n}\n\ntemplate < typename T, typename V >\ntypename\
    \ enable_if< is_class< T >::value != 0 >::type fill_v(\n    T &t, const V &v)\
    \ {\n  for (auto &e: t) fill_v(e, v);\n}\n\ntemplate < typename F >\nstruct FixPoint:\
    \ F {\n  explicit FixPoint(F &&f): F(forward< F >(f)) {}\n\n  template < typename...\
    \ Args >\n  decltype(auto) operator()(Args &&...args) const {\n    return F::operator()(*this,\
    \ forward< Args >(args)...);\n  }\n};\n\ntemplate < typename F >\ninline decltype(auto)\
    \ MFP(F &&f) {\n  return FixPoint< F >{forward< F >(f)};\n}\n#line 5 \"test/verify/yosupo-line-add-get-min-2.test.cpp\"\
    \n\nint main() {\n  int N, Q;\n  cin >> N >> Q;\n  using CHT = ConvexHullTrickAddMonotone<\
    \ int64, true >;\n  vector< CHT > cht;\n  auto add = [&](int64 a, int64 b) {\n\
    \    cht.emplace_back();\n    cht.back().add(a, b);\n    while (cht.size() >=\
    \ 2 and\n           cht.back().H.size() >= cht[cht.size() - 2].H.size()) {\n \
    \     auto X = cht.back().H;\n      cht.pop_back();\n      auto Y = cht.back().H;\n\
    \      cht.pop_back();\n      reverse(begin(X), end(X));\n      reverse(begin(Y),\
    \ end(Y));\n      CHT c;\n      int k = 0;\n      for (auto &p: X) {\n       \
    \ while (k < (int)Y.size() and Y[k] < p) {\n          c.add(Y[k].first, Y[k].second);\n\
    \          ++k;\n        }\n        c.add(p.first, p.second);\n      }\n     \
    \ while (k < (int)Y.size()) {\n        c.add(Y[k].first, Y[k].second);\n     \
    \   ++k;\n      }\n      cht.emplace_back(c);\n    }\n  };\n  for (int i = 0;\
    \ i < N; i++) {\n    int64 a, b;\n    cin >> a >> b;\n    add(a, b);\n  }\n  while\
    \ (Q--) {\n    int t;\n    cin >> t;\n    if (t == 0) {\n      int64 a, b;\n \
    \     cin >> a >> b;\n      add(a, b);\n    } else {\n      int64 x;\n      cin\
    \ >> x;\n      int64 ret = infll;\n      for (auto &c: cht) {\n        chmin(ret,\
    \ c.query(x));\n      }\n      cout << ret << \"\\n\";\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n\
    #include \"../../structure/convex-hull-trick/convex-hull-trick-add-monotone.hpp\"\
    \n#include \"../../template/template.hpp\"\n\nint main() {\n  int N, Q;\n  cin\
    \ >> N >> Q;\n  using CHT = ConvexHullTrickAddMonotone< int64, true >;\n  vector<\
    \ CHT > cht;\n  auto add = [&](int64 a, int64 b) {\n    cht.emplace_back();\n\
    \    cht.back().add(a, b);\n    while (cht.size() >= 2 and\n           cht.back().H.size()\
    \ >= cht[cht.size() - 2].H.size()) {\n      auto X = cht.back().H;\n      cht.pop_back();\n\
    \      auto Y = cht.back().H;\n      cht.pop_back();\n      reverse(begin(X),\
    \ end(X));\n      reverse(begin(Y), end(Y));\n      CHT c;\n      int k = 0;\n\
    \      for (auto &p: X) {\n        while (k < (int)Y.size() and Y[k] < p) {\n\
    \          c.add(Y[k].first, Y[k].second);\n          ++k;\n        }\n      \
    \  c.add(p.first, p.second);\n      }\n      while (k < (int)Y.size()) {\n   \
    \     c.add(Y[k].first, Y[k].second);\n        ++k;\n      }\n      cht.emplace_back(c);\n\
    \    }\n  };\n  for (int i = 0; i < N; i++) {\n    int64 a, b;\n    cin >> a >>\
    \ b;\n    add(a, b);\n  }\n  while (Q--) {\n    int t;\n    cin >> t;\n    if\
    \ (t == 0) {\n      int64 a, b;\n      cin >> a >> b;\n      add(a, b);\n    }\
    \ else {\n      int64 x;\n      cin >> x;\n      int64 ret = infll;\n      for\
    \ (auto &c: cht) {\n        chmin(ret, c.query(x));\n      }\n      cout << ret\
    \ << \"\\n\";\n    }\n  }\n}\n"
  dependsOn:
  - structure/convex-hull-trick/convex-hull-trick-add-monotone.hpp
  - template/template.hpp
  isVerificationFile: true
  path: test/verify/yosupo-line-add-get-min-2.test.cpp
  requiredBy: []
  timestamp: '2022-08-27 15:55:50+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/verify/yosupo-line-add-get-min-2.test.cpp
layout: document
redirect_from:
- /verify/test/verify/yosupo-line-add-get-min-2.test.cpp
- /verify/test/verify/yosupo-line-add-get-min-2.test.cpp.html
title: test/verify/yosupo-line-add-get-min-2.test.cpp
---
