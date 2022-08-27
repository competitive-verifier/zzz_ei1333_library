---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: geometry/base.hpp
    title: geometry/base.hpp
  - icon: ':x:'
    path: geometry/point.hpp
    title: geometry/point.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/base.hpp\"\n\nnamespace geometry {\n  using Real\
    \     = double;\n  const Real EPS = 1e-8;\n  const Real PI  = acos(static_cast<\
    \ Real >(-1));\n\n  enum { OUT, ON, IN };\n\n  inline int sign(const Real &r)\
    \ {\n    return r <= -EPS ? -1 : r >= EPS ? 1 : 0;\n  }\n\n  inline bool equals(const\
    \ Real &a, const Real &b) {\n    return sign(a - b) == 0;\n  }\n} // namespace\
    \ geometry\n#line 3 \"geometry/point.hpp\"\n\nnamespace geometry {\n  using Point\
    \ = complex< Real >;\n\n  istream &operator>>(istream &is, Point &p) {\n    Real\
    \ a, b;\n    is >> a >> b;\n    p = Point(a, b);\n    return is;\n  }\n\n  ostream\
    \ &operator<<(ostream &os, const Point &p) {\n    return os << real(p) << \" \"\
    \ << imag(p);\n  }\n\n  Point operator*(const Point &p, const Real &d) {\n   \
    \ return Point(real(p) * d, imag(p) * d);\n  }\n\n  // rotate point p counterclockwise\
    \ by theta rad\n  Point rotate(Real theta, const Point &p) {\n    return Point(cos(theta)\
    \ * real(p) - sin(theta) * imag(p),\n                 sin(theta) * real(p) + cos(theta)\
    \ * imag(p));\n  }\n\n  Real cross(const Point &a, const Point &b) {\n    return\
    \ real(a) * imag(b) - imag(a) * real(b);\n  }\n\n  Real dot(const Point &a, const\
    \ Point &b) {\n    return real(a) * real(b) + imag(a) * imag(b);\n  }\n\n  bool\
    \ compare_x(const Point &a, const Point &b) {\n    return equals(real(a), real(b))\
    \ ? imag(a) < imag(b)\n                                    : real(a) < real(b);\n\
    \  }\n\n  bool compare_y(const Point &a, const Point &b) {\n    return equals(imag(a),\
    \ imag(b)) ? real(a) < real(b)\n                                    : imag(a)\
    \ < imag(b);\n  }\n\n  using Points = vector< Point >;\n} // namespace geometry\n\
    #line 2 \"geometry/angle.hpp\"\n\nnamespace geometry {\n  Real radian_to_degree(const\
    \ Real &theta) {\n    return theta * 180.0 / PI;\n  }\n\n  Real degree_to_radian(const\
    \ Real &deg) {\n    return deg * PI / 180.0;\n  }\n\n  // smaller angle of the\
    \ a-b-c\n  Real get_smaller_angle(const Point &a, const Point &b,\n          \
    \               const Point &c) {\n    const Point v(a - b), w(c - b);\n    auto\
    \ alpha = atan2(imag(v), real(v));\n    auto beta  = atan2(imag(w), real(w));\n\
    \    if (alpha > beta) swap(alpha, beta);\n    Real theta = (beta - alpha);\n\
    \    return min(theta, 2 * PI - theta);\n  }\n} // namespace geometry\n"
  code: "#include \"point.hpp\"\n\nnamespace geometry {\n  Real radian_to_degree(const\
    \ Real &theta) {\n    return theta * 180.0 / PI;\n  }\n\n  Real degree_to_radian(const\
    \ Real &deg) {\n    return deg * PI / 180.0;\n  }\n\n  // smaller angle of the\
    \ a-b-c\n  Real get_smaller_angle(const Point &a, const Point &b,\n          \
    \               const Point &c) {\n    const Point v(a - b), w(c - b);\n    auto\
    \ alpha = atan2(imag(v), real(v));\n    auto beta  = atan2(imag(w), real(w));\n\
    \    if (alpha > beta) swap(alpha, beta);\n    Real theta = (beta - alpha);\n\
    \    return min(theta, 2 * PI - theta);\n  }\n} // namespace geometry\n"
  dependsOn:
  - geometry/point.hpp
  - geometry/base.hpp
  isVerificationFile: false
  path: geometry/angle.hpp
  requiredBy: []
  timestamp: '2022-08-27 15:55:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/angle.hpp
layout: document
redirect_from:
- /library/geometry/angle.hpp
- /library/geometry/angle.hpp.html
title: geometry/angle.hpp
---
