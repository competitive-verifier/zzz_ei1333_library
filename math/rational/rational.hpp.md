---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/verify/yukicoder-1236.test.cpp
    title: test/verify/yukicoder-1236.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "Rational (\u6709\u7406\u6570\u578B)"
    links: []
  bundledCode: "#line 1 \"math/rational/rational.hpp\"\n/**\n * @brief Rational (\u6709\
    \u7406\u6570\u578B)\n */\ntemplate < typename T >\nstruct Rational {\n private:\n\
    \  T num, den;\n\n  static T gcd(T a, T b) {\n    if (a < 0) a = -a;\n    if (b\
    \ < 0) b = -b;\n    return std::__gcd(a, b);\n  }\n\n  void normalize() {\n  \
    \  if (num == 0) {\n      den = 1;\n    } else {\n      T g = gcd(num, den);\n\
    \      num /= g;\n      den /= g;\n      if (den < 0) {\n        num = -num;\n\
    \        den = -den;\n      }\n    }\n  }\n\n public:\n  Rational(): num(0), den(1)\
    \ {}\n\n  explicit Rational(const T &n): num(n), den(1) {}\n\n  explicit Rational(const\
    \ T &n, const T &d): num(n), den(d) {\n    normalize();\n  }\n\n  Rational &operator=(const\
    \ T &n) {\n    return assign(n, 1);\n  }\n\n  Rational &assign(const T &n, const\
    \ T &d) {\n    num = n;\n    den = d;\n    normalize();\n    return *this;\n \
    \ }\n\n  T numerator() const {\n    return num;\n  }\n\n  T denominator() const\
    \ {\n    return den;\n  }\n\n  Rational &operator+=(const Rational &r) {\n   \
    \ T r_num = r.num, r_den = r.den;\n    T g = gcd(den, r_den);\n    den /= g;\n\
    \    num = num * (r_den / g) + r_num * den;\n    g   = gcd(num, g);\n    num /=\
    \ g;\n    den *= r_den / g;\n    return *this;\n  }\n\n  Rational &operator-=(const\
    \ Rational &r) {\n    T r_num = r.num, r_den = r.den;\n    T g = gcd(den, r_den);\n\
    \    den /= g;\n    num = num * (r_den / g) - r_num * den;\n    g   = gcd(num,\
    \ g);\n    num /= g;\n    den *= r_den / g;\n    return *this;\n  }\n\n  Rational\
    \ &operator*=(const Rational &r) {\n    T r_num = r.num, r_den = r.den;\n    T\
    \ g1 = gcd(num, r_den);\n    T g2 = gcd(den, r_num);\n    num  = (num / g1) *\
    \ (r_num / g2);\n    den  = (den / g2) * (r_den / g1);\n    return *this;\n  }\n\
    \n  Rational &operator/=(const Rational &r) {\n    T r_num = r.num, r_den = r.den;\n\
    \    T g1 = gcd(num, r_num);\n    T g2 = gcd(den, r_den);\n    num  = (num / g1)\
    \ * (r_den / g2);\n    den  = (den / g2) * (r_num / g1);\n    if (den < 0) {\n\
    \      num = -num;\n      den = -den;\n    }\n    return *this;\n  }\n\n  Rational\
    \ &operator+=(const T &i) {\n    return (*this) += Rational{i};\n  }\n\n  Rational\
    \ &operator-=(const T &i) {\n    return (*this) -= Rational{i};\n  }\n\n  Rational\
    \ &operator*=(const T &i) {\n    return (*this) *= Rational{i};\n  }\n\n  Rational\
    \ &operator/=(const T &i) {\n    return (*this) /= Rational{i};\n  }\n\n  Rational\
    \ operator+(const Rational &r) const {\n    return Rational(*this) += r;\n  }\n\
    \n  Rational operator-(const Rational &r) const {\n    return Rational(*this)\
    \ -= r;\n  }\n\n  Rational operator*(const Rational &r) const {\n    return Rational(*this)\
    \ *= r;\n  }\n\n  Rational operator/(const Rational &r) const {\n    return Rational(*this)\
    \ /= r;\n  }\n\n  Rational operator+(const T &i) const {\n    return Rational(*this)\
    \ += i;\n  }\n\n  Rational operator-(const T &i) const {\n    return Rational(*this)\
    \ -= i;\n  }\n\n  Rational operator*(const T &i) const {\n    return Rational(*this)\
    \ *= i;\n  }\n\n  Rational operator/(const T &i) const {\n    return Rational(*this)\
    \ /= i;\n  }\n\n  Rational operator-() const {\n    return Rational{-num, den};\n\
    \  }\n\n  Rational &operator++() {\n    num += den;\n    return *this;\n  }\n\n\
    \  Rational &operator--() {\n    num -= den;\n    return *this;\n  }\n\n#define\
    \ define_cmp(op)                        \\\n  bool operator op(const Rational\
    \ &r) const { \\\n    return num * r.den op r.num * den;        \\\n  }\n\n  define_cmp(==)\n\
    \n      define_cmp(!=)\n\n          define_cmp(<)\n\n              define_cmp(>)\n\
    \n                  define_cmp(<=)\n\n                      define_cmp(>=)\n\n\
    #undef define_cmp\n\n                          template < typename Real = double\
    \ >\n                          Real to_double() const {\n    return static_cast<\
    \ Real >(numerator()) / denominator();\n  }\n\n  Rational abs() const {\n    return\
    \ Rational{num < 0 ? -num : num, den};\n  }\n\n  friend ostream &operator<<(ostream\
    \ &os, const Rational &r) {\n    return os << r.numerator() << \"/\" << r.denominator();\n\
    \  }\n};\n"
  code: "/**\n * @brief Rational (\u6709\u7406\u6570\u578B)\n */\ntemplate < typename\
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
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/rational/rational.hpp
  requiredBy: []
  timestamp: '2022-08-27 15:55:50+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/verify/yukicoder-1236.test.cpp
documentation_of: math/rational/rational.hpp
layout: document
redirect_from:
- /library/math/rational/rational.hpp
- /library/math/rational/rational.hpp.html
title: "Rational (\u6709\u7406\u6570\u578B)"
---
