---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/others/cartesian-tree.hpp
    title: Cartesian Tree
  - icon: ':question:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/cartesian_tree
    links:
    - https://judge.yosupo.jp/problem/cartesian_tree
  bundledCode: "#line 1 \"test/verify/yosupo-cartesian-tree.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/cartesian_tree\"\n\n#line 1 \"template/template.cpp\"\
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
    \ MFP(F &&f) {\n  return FixPoint< F >{forward< F >(f)};\n}\n#line 4 \"test/verify/yosupo-cartesian-tree.test.cpp\"\
    \n\n#line 2 \"graph/others/cartesian-tree.hpp\"\n/**\n * @brief Cartesian Tree\n\
    \ * @docs docs/cartesian-tree.md\n * @see https://kimiyuki.net/blog/2020/07/27/recursion-on-cartesian-tree/\n\
    \ */\ntemplate< typename T >\nvector< int > cartesian_tree(const vector< T > &v)\
    \ {\n  int n = (int) v.size();\n  vector< int > par(n, -1);\n  stack< int > st;\n\
    \  for(int i = 0; i < n; i++) {\n    int last = -1;\n    while(!st.empty() &&\
    \ v[st.top()] >= v[i]) {\n      last = st.top();\n      st.pop();\n    }\n   \
    \ if(!st.empty()) par[i] = st.top();\n    if(last >= 0) par[last] = i;\n    st.emplace(i);\n\
    \  }\n  return par;\n}\n#line 6 \"test/verify/yosupo-cartesian-tree.test.cpp\"\
    \n\nint main() {\n  int N;\n  cin >> N;\n  vector< int > A(N);\n  for(auto &a\
    \ : A) cin >> a;\n  auto p = cartesian_tree(A);\n  for(int i = 0; i < N; i++)\
    \ {\n    if(p[i] >= 0) cout << p[i] << \" \";\n    else cout << i << \" \";\n\
    \  }\n  cout << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/cartesian_tree\"\n\n#include\
    \ \"../../template/template.cpp\"\n\n#include \"../../graph/others/cartesian-tree.hpp\"\
    \n\nint main() {\n  int N;\n  cin >> N;\n  vector< int > A(N);\n  for(auto &a\
    \ : A) cin >> a;\n  auto p = cartesian_tree(A);\n  for(int i = 0; i < N; i++)\
    \ {\n    if(p[i] >= 0) cout << p[i] << \" \";\n    else cout << i << \" \";\n\
    \  }\n  cout << \"\\n\";\n}\n"
  dependsOn:
  - template/template.cpp
  - graph/others/cartesian-tree.hpp
  isVerificationFile: true
  path: test/verify/yosupo-cartesian-tree.test.cpp
  requiredBy: []
  timestamp: '2021-07-21 02:10:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/yosupo-cartesian-tree.test.cpp
layout: document
redirect_from:
- /verify/test/verify/yosupo-cartesian-tree.test.cpp
- /verify/test/verify/yosupo-cartesian-tree.test.cpp.html
title: test/verify/yosupo-cartesian-tree.test.cpp
---
