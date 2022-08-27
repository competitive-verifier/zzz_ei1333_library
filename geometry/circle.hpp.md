---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: geometry/base.hpp
    title: geometry/base.hpp
  - icon: ':x:'
    path: geometry/point.hpp
    title: geometry/point.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: geometry/common_area_cp.hpp
    title: geometry/common_area_cp.hpp
  - icon: ':x:'
    path: geometry/cross_point_cc.hpp
    title: geometry/cross_point_cc.hpp
  - icon: ':x:'
    path: geometry/cross_point_cl.hpp
    title: geometry/cross_point_cl.hpp
  - icon: ':warning:'
    path: geometry/cross_point_cs.hpp
    title: geometry/cross_point_cs.hpp
  - icon: ':warning:'
    path: geometry/is_intersect_cl.hpp
    title: geometry/is_intersect_cl.hpp
  - icon: ':warning:'
    path: geometry/is_intersect_cp.hpp
    title: geometry/is_intersect_cp.hpp
  - icon: ':x:'
    path: geometry/is_intersect_cs.hpp
    title: geometry/is_intersect_cs.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/verify/aoj-cgl-7-d.test.cpp
    title: test/verify/aoj-cgl-7-d.test.cpp
  - icon: ':x:'
    path: test/verify/aoj-cgl-7-e.test.cpp
    title: test/verify/aoj-cgl-7-e.test.cpp
  - icon: ':x:'
    path: test/verify/aoj-cgl-7-h.test.cpp
    title: test/verify/aoj-cgl-7-h.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
    #line 3 \"geometry/circle.hpp\"\n\nnamespace geometry {\n  struct Circle {\n \
    \   Point p;\n    Real r{};\n\n    Circle() = default;\n\n    Circle(const Point\
    \ &p, const Real &r): p(p), r(r) {}\n  };\n\n  using Circles = vector< Circle\
    \ >;\n} // namespace geometry\n"
  code: "#pragma once\n#include \"point.hpp\"\n\nnamespace geometry {\n  struct Circle\
    \ {\n    Point p;\n    Real r{};\n\n    Circle() = default;\n\n    Circle(const\
    \ Point &p, const Real &r): p(p), r(r) {}\n  };\n\n  using Circles = vector< Circle\
    \ >;\n} // namespace geometry\n"
  dependsOn:
  - geometry/point.hpp
  - geometry/base.hpp
  isVerificationFile: false
  path: geometry/circle.hpp
  requiredBy:
  - geometry/cross_point_cc.hpp
  - geometry/is_intersect_cl.hpp
  - geometry/is_intersect_cs.hpp
  - geometry/is_intersect_cp.hpp
  - geometry/cross_point_cs.hpp
  - geometry/cross_point_cl.hpp
  - geometry/common_area_cp.hpp
  timestamp: '2022-08-27 15:55:50+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/verify/aoj-cgl-7-h.test.cpp
  - test/verify/aoj-cgl-7-d.test.cpp
  - test/verify/aoj-cgl-7-e.test.cpp
documentation_of: geometry/circle.hpp
layout: document
redirect_from:
- /library/geometry/circle.hpp
- /library/geometry/circle.hpp.html
title: geometry/circle.hpp
---
