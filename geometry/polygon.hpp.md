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
    path: geometry/area.hpp
    title: geometry/area.hpp
  - icon: ':x:'
    path: geometry/common_area_cp.hpp
    title: geometry/common_area_cp.hpp
  - icon: ':x:'
    path: geometry/contains.hpp
    title: geometry/contains.hpp
  - icon: ':x:'
    path: geometry/convex_hull.hpp
    title: geometry/convex_hull.hpp
  - icon: ':x:'
    path: geometry/convex_polygon_contains.hpp
    title: geometry/convex_polygon_contains.hpp
  - icon: ':x:'
    path: geometry/convex_polygon_cut.hpp
    title: geometry/convex_polygon_cut.hpp
  - icon: ':x:'
    path: geometry/convex_polygon_diameter.hpp
    title: geometry/convex_polygon_diameter.hpp
  - icon: ':x:'
    path: geometry/is_convex_polygon.hpp
    title: geometry/is_convex_polygon.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/verify/aoj-0412.test.cpp
    title: test/verify/aoj-0412.test.cpp
  - icon: ':x:'
    path: test/verify/aoj-cgl-3-a.test.cpp
    title: test/verify/aoj-cgl-3-a.test.cpp
  - icon: ':x:'
    path: test/verify/aoj-cgl-3-b.test.cpp
    title: test/verify/aoj-cgl-3-b.test.cpp
  - icon: ':x:'
    path: test/verify/aoj-cgl-3-c.test.cpp
    title: test/verify/aoj-cgl-3-c.test.cpp
  - icon: ':x:'
    path: test/verify/aoj-cgl-4-a.test.cpp
    title: test/verify/aoj-cgl-4-a.test.cpp
  - icon: ':x:'
    path: test/verify/aoj-cgl-4-b.test.cpp
    title: test/verify/aoj-cgl-4-b.test.cpp
  - icon: ':x:'
    path: test/verify/aoj-cgl-4-c.test.cpp
    title: test/verify/aoj-cgl-4-c.test.cpp
  - icon: ':x:'
    path: test/verify/aoj-cgl-7-h.test.cpp
    title: test/verify/aoj-cgl-7-h.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/polygon.hpp\"\n\n#line 2 \"geometry/base.hpp\"\n\
    \nnamespace geometry {\n  using Real     = double;\n  const Real EPS = 1e-8;\n\
    \  const Real PI  = acos(static_cast< Real >(-1));\n\n  enum { OUT, ON, IN };\n\
    \n  inline int sign(const Real &r) {\n    return r <= -EPS ? -1 : r >= EPS ? 1\
    \ : 0;\n  }\n\n  inline bool equals(const Real &a, const Real &b) {\n    return\
    \ sign(a - b) == 0;\n  }\n} // namespace geometry\n#line 3 \"geometry/point.hpp\"\
    \n\nnamespace geometry {\n  using Point = complex< Real >;\n\n  istream &operator>>(istream\
    \ &is, Point &p) {\n    Real a, b;\n    is >> a >> b;\n    p = Point(a, b);\n\
    \    return is;\n  }\n\n  ostream &operator<<(ostream &os, const Point &p) {\n\
    \    return os << real(p) << \" \" << imag(p);\n  }\n\n  Point operator*(const\
    \ Point &p, const Real &d) {\n    return Point(real(p) * d, imag(p) * d);\n  }\n\
    \n  // rotate point p counterclockwise by theta rad\n  Point rotate(Real theta,\
    \ const Point &p) {\n    return Point(cos(theta) * real(p) - sin(theta) * imag(p),\n\
    \                 sin(theta) * real(p) + cos(theta) * imag(p));\n  }\n\n  Real\
    \ cross(const Point &a, const Point &b) {\n    return real(a) * imag(b) - imag(a)\
    \ * real(b);\n  }\n\n  Real dot(const Point &a, const Point &b) {\n    return\
    \ real(a) * real(b) + imag(a) * imag(b);\n  }\n\n  bool compare_x(const Point\
    \ &a, const Point &b) {\n    return equals(real(a), real(b)) ? imag(a) < imag(b)\n\
    \                                    : real(a) < real(b);\n  }\n\n  bool compare_y(const\
    \ Point &a, const Point &b) {\n    return equals(imag(a), imag(b)) ? real(a) <\
    \ real(b)\n                                    : imag(a) < imag(b);\n  }\n\n \
    \ using Points = vector< Point >;\n} // namespace geometry\n#line 4 \"geometry/polygon.hpp\"\
    \n\nnamespace geometry {\n  using Polygon  = vector< Point >;\n  using Polygons\
    \ = vector< Polygon >;\n} // namespace geometry\n"
  code: "#pragma once\n\n#include \"point.hpp\"\n\nnamespace geometry {\n  using Polygon\
    \  = vector< Point >;\n  using Polygons = vector< Polygon >;\n} // namespace geometry\n"
  dependsOn:
  - geometry/point.hpp
  - geometry/base.hpp
  isVerificationFile: false
  path: geometry/polygon.hpp
  requiredBy:
  - geometry/area.hpp
  - geometry/is_convex_polygon.hpp
  - geometry/convex_polygon_contains.hpp
  - geometry/convex_polygon_cut.hpp
  - geometry/common_area_cp.hpp
  - geometry/convex_polygon_diameter.hpp
  - geometry/convex_hull.hpp
  - geometry/contains.hpp
  timestamp: '2022-08-27 15:55:50+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/verify/aoj-cgl-3-a.test.cpp
  - test/verify/aoj-cgl-3-c.test.cpp
  - test/verify/aoj-cgl-4-a.test.cpp
  - test/verify/aoj-0412.test.cpp
  - test/verify/aoj-cgl-7-h.test.cpp
  - test/verify/aoj-cgl-4-b.test.cpp
  - test/verify/aoj-cgl-3-b.test.cpp
  - test/verify/aoj-cgl-4-c.test.cpp
documentation_of: geometry/polygon.hpp
layout: document
redirect_from:
- /library/geometry/polygon.hpp
- /library/geometry/polygon.hpp.html
title: geometry/polygon.hpp
---
