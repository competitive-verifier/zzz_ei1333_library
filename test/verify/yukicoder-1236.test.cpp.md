---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/rational/rational.hpp
    title: "Rational (\u6709\u7406\u6570\u578B)"
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
    PROBLEM: https://yukicoder.me/problems/no/1236
    links:
    - https://yukicoder.me/problems/no/1236
  bundledCode: "#line 1 \"test/verify/yukicoder-1236.test.cpp\"\n#define PROBLEM \"\
    https://yukicoder.me/problems/no/1236\"\n\n#line 1 \"math/rational/rational.hpp\"\
    \n/**\n * @brief Rational (\u6709\u7406\u6570\u578B)\n */\ntemplate < typename\
    \ T >\nstruct Rational {\n private:\n  T num, den;\n\n  static T gcd(T a, T b)\
    \ {\n    if (a < 0) a = -a;\n    if (b < 0) b = -b;\n    return std::__gcd(a,\
    \ b);\n  }\n\n  void normalize() {\n    if (num == 0) {\n      den = 1;\n    }\
    \ else {\n      T g = gcd(num, den);\n      num /= g;\n      den /= g;\n     \
    \ if (den < 0) {\n        num = -num;\n        den = -den;\n      }\n    }\n \
    \ }\n\n public:\n  Rational(): num(0), den(1) {}\n\n  explicit Rational(const\
    \ T &n): num(n), den(1) {}\n\n  explicit Rational(const T &n, const T &d): num(n),\
    \ den(d) {\n    normalize();\n  }\n\n  Rational &operator=(const T &n) {\n   \
    \ return assign(n, 1);\n  }\n\n  Rational &assign(const T &n, const T &d) {\n\
    \    num = n;\n    den = d;\n    normalize();\n    return *this;\n  }\n\n  T numerator()\
    \ const {\n    return num;\n  }\n\n  T denominator() const {\n    return den;\n\
    \  }\n\n  Rational &operator+=(const Rational &r) {\n    T r_num = r.num, r_den\
    \ = r.den;\n    T g = gcd(den, r_den);\n    den /= g;\n    num = num * (r_den\
    \ / g) + r_num * den;\n    g   = gcd(num, g);\n    num /= g;\n    den *= r_den\
    \ / g;\n    return *this;\n  }\n\n  Rational &operator-=(const Rational &r) {\n\
    \    T r_num = r.num, r_den = r.den;\n    T g = gcd(den, r_den);\n    den /= g;\n\
    \    num = num * (r_den / g) - r_num * den;\n    g   = gcd(num, g);\n    num /=\
    \ g;\n    den *= r_den / g;\n    return *this;\n  }\n\n  Rational &operator*=(const\
    \ Rational &r) {\n    T r_num = r.num, r_den = r.den;\n    T g1 = gcd(num, r_den);\n\
    \    T g2 = gcd(den, r_num);\n    num  = (num / g1) * (r_num / g2);\n    den \
    \ = (den / g2) * (r_den / g1);\n    return *this;\n  }\n\n  Rational &operator/=(const\
    \ Rational &r) {\n    T r_num = r.num, r_den = r.den;\n    T g1 = gcd(num, r_num);\n\
    \    T g2 = gcd(den, r_den);\n    num  = (num / g1) * (r_den / g2);\n    den \
    \ = (den / g2) * (r_num / g1);\n    if (den < 0) {\n      num = -num;\n      den\
    \ = -den;\n    }\n    return *this;\n  }\n\n  Rational &operator+=(const T &i)\
    \ {\n    return (*this) += Rational{i};\n  }\n\n  Rational &operator-=(const T\
    \ &i) {\n    return (*this) -= Rational{i};\n  }\n\n  Rational &operator*=(const\
    \ T &i) {\n    return (*this) *= Rational{i};\n  }\n\n  Rational &operator/=(const\
    \ T &i) {\n    return (*this) /= Rational{i};\n  }\n\n  Rational operator+(const\
    \ Rational &r) const {\n    return Rational(*this) += r;\n  }\n\n  Rational operator-(const\
    \ Rational &r) const {\n    return Rational(*this) -= r;\n  }\n\n  Rational operator*(const\
    \ Rational &r) const {\n    return Rational(*this) *= r;\n  }\n\n  Rational operator/(const\
    \ Rational &r) const {\n    return Rational(*this) /= r;\n  }\n\n  Rational operator+(const\
    \ T &i) const {\n    return Rational(*this) += i;\n  }\n\n  Rational operator-(const\
    \ T &i) const {\n    return Rational(*this) -= i;\n  }\n\n  Rational operator*(const\
    \ T &i) const {\n    return Rational(*this) *= i;\n  }\n\n  Rational operator/(const\
    \ T &i) const {\n    return Rational(*this) /= i;\n  }\n\n  Rational operator-()\
    \ const {\n    return Rational{-num, den};\n  }\n\n  Rational &operator++() {\n\
    \    num += den;\n    return *this;\n  }\n\n  Rational &operator--() {\n    num\
    \ -= den;\n    return *this;\n  }\n\n#define define_cmp(op)                  \
    \      \\\n  bool operator op(const Rational &r) const { \\\n    return num *\
    \ r.den op r.num * den;        \\\n  }\n\n  define_cmp(==)\n\n      define_cmp(!=)\n\
    \n          define_cmp(<)\n\n              define_cmp(>)\n\n                 \
    \ define_cmp(<=)\n\n                      define_cmp(>=)\n\n#undef define_cmp\n\
    \n                          template < typename Real = double >\n            \
    \              Real to_double() const {\n    return static_cast< Real >(numerator())\
    \ / denominator();\n  }\n\n  Rational abs() const {\n    return Rational{num <\
    \ 0 ? -num : num, den};\n  }\n\n  friend ostream &operator<<(ostream &os, const\
    \ Rational &r) {\n    return os << r.numerator() << \"/\" << r.denominator();\n\
    \  }\n};\n#line 1 \"template/template.hpp\"\n#include <bits/stdc++.h>\n\nusing\
    \ namespace std;\n\nusing int64   = long long;\nconst int mod = 1e9 + 7;\n\nconst\
    \ int64 infll = (1LL << 62) - 1;\nconst int inf     = (1 << 30) - 1;\n\nstruct\
    \ IoSetup {\n  IoSetup() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \    cout << fixed << setprecision(10);\n    cerr << fixed << setprecision(10);\n\
    \  }\n} iosetup;\n\ntemplate < typename T1, typename T2 >\nostream &operator<<(ostream\
    \ &os, const pair< T1, T2 > &p) {\n  os << p.first << \" \" << p.second;\n  return\
    \ os;\n}\n\ntemplate < typename T1, typename T2 >\nistream &operator>>(istream\
    \ &is, pair< T1, T2 > &p) {\n  is >> p.first >> p.second;\n  return is;\n}\n\n\
    template < typename T >\nostream &operator<<(ostream &os, const vector< T > &v)\
    \ {\n  for (int i = 0; i < (int)v.size(); i++) {\n    os << v[i] << (i + 1 !=\
    \ v.size() ? \" \" : \"\");\n  }\n  return os;\n}\n\ntemplate < typename T >\n\
    istream &operator>>(istream &is, vector< T > &v) {\n  for (T &in: v) is >> in;\n\
    \  return is;\n}\n\ntemplate < typename T1, typename T2 >\ninline bool chmax(T1\
    \ &a, T2 b) {\n  return a < b && (a = b, true);\n}\n\ntemplate < typename T1,\
    \ typename T2 >\ninline bool chmin(T1 &a, T2 b) {\n  return a > b && (a = b, true);\n\
    }\n\ntemplate < typename T = int64 >\nvector< T > make_v(size_t a) {\n  return\
    \ vector< T >(a);\n}\n\ntemplate < typename T, typename... Ts >\nauto make_v(size_t\
    \ a, Ts... ts) {\n  return vector< decltype(make_v< T >(ts...)) >(a,\n       \
    \                                         make_v< T >(ts...));\n}\n\ntemplate\
    \ < typename T, typename V >\ntypename enable_if< is_class< T >::value == 0 >::type\
    \ fill_v(\n    T &t, const V &v) {\n  t = v;\n}\n\ntemplate < typename T, typename\
    \ V >\ntypename enable_if< is_class< T >::value != 0 >::type fill_v(\n    T &t,\
    \ const V &v) {\n  for (auto &e: t) fill_v(e, v);\n}\n\ntemplate < typename F\
    \ >\nstruct FixPoint: F {\n  explicit FixPoint(F &&f): F(forward< F >(f)) {}\n\
    \n  template < typename... Args >\n  decltype(auto) operator()(Args &&...args)\
    \ const {\n    return F::operator()(*this, forward< Args >(args)...);\n  }\n};\n\
    \ntemplate < typename F >\ninline decltype(auto) MFP(F &&f) {\n  return FixPoint<\
    \ F >{forward< F >(f)};\n}\n#line 5 \"test/verify/yukicoder-1236.test.cpp\"\n\n\
    int main() {\n  string s, t;\n  cin >> s >> t;\n  int a   = stoi(s);\n  int b\
    \   = stoi(t);\n  using F = Rational< int >;\n  F c(a * 60 + b);\n  F d(720, 11);\n\
    \  F x(0);\n  while (x < c) x += d;\n  x = x - c;\n  cout << x.numerator() * 60\
    \ / x.denominator() << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1236\"\n\n#include \"\
    ../../math/rational/rational.hpp\"\n#include \"../../template/template.hpp\"\n\
    \nint main() {\n  string s, t;\n  cin >> s >> t;\n  int a   = stoi(s);\n  int\
    \ b   = stoi(t);\n  using F = Rational< int >;\n  F c(a * 60 + b);\n  F d(720,\
    \ 11);\n  F x(0);\n  while (x < c) x += d;\n  x = x - c;\n  cout << x.numerator()\
    \ * 60 / x.denominator() << \"\\n\";\n}\n"
  dependsOn:
  - math/rational/rational.hpp
  - template/template.hpp
  isVerificationFile: true
  path: test/verify/yukicoder-1236.test.cpp
  requiredBy: []
  timestamp: '2022-08-27 15:55:50+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/verify/yukicoder-1236.test.cpp
layout: document
redirect_from:
- /verify/test/verify/yukicoder-1236.test.cpp
- /verify/test/verify/yukicoder-1236.test.cpp.html
title: test/verify/yukicoder-1236.test.cpp
---
