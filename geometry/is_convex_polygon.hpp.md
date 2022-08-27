---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: geometry/base.hpp
    title: geometry/base.hpp
  - icon: ':x:'
    path: geometry/ccw.hpp
    title: geometry/ccw.hpp
  - icon: ':x:'
    path: geometry/point.hpp
    title: geometry/point.hpp
  - icon: ':x:'
    path: geometry/polygon.hpp
    title: geometry/polygon.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/verify/aoj-cgl-3-b.test.cpp
    title: test/verify/aoj-cgl-3-b.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_B
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
    #line 3 \"geometry/ccw.hpp\"\n\nnamespace geometry {\n  // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C\n\
    \  constexpr int COUNTER_CLOCKWISE = +1;\n  constexpr int CLOCKWISE         =\
    \ -1;\n  constexpr int ONLINE_BACK       = +2; // c-a-b\n  constexpr int ONLINE_FRONT\
    \      = -2; // a-b-c\n  constexpr int ON_SEGMENT        = 0;  // a-c-b\n  int\
    \ ccw(const Point &a, Point b, Point c) {\n    b = b - a, c = c - a;\n    if (sign(cross(b,\
    \ c)) == +1) return COUNTER_CLOCKWISE;\n    if (sign(cross(b, c)) == -1) return\
    \ CLOCKWISE;\n    if (sign(dot(b, c)) == -1) return ONLINE_BACK;\n    if (norm(b)\
    \ < norm(c)) return ONLINE_FRONT;\n    return ON_SEGMENT;\n  }\n} // namespace\
    \ geometry\n#line 2 \"geometry/polygon.hpp\"\n\n#line 4 \"geometry/polygon.hpp\"\
    \n\nnamespace geometry {\n  using Polygon  = vector< Point >;\n  using Polygons\
    \ = vector< Polygon >;\n} // namespace geometry\n#line 4 \"geometry/is_convex_polygon.hpp\"\
    \n\nnamespace geometry {\n  // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_B\n\
    \  bool is_convex_polygon(const Polygon &p) {\n    int n = (int)p.size();\n  \
    \  for (int i = 0; i < n; i++) {\n      if (ccw(p[(i + n - 1) % n], p[i], p[(i\
    \ + 1) % n]) == CLOCKWISE)\n        return false;\n    }\n    return true;\n \
    \ }\n} // namespace geometry\n"
  code: "#include \"ccw.hpp\"\n#include \"point.hpp\"\n#include \"polygon.hpp\"\n\n\
    namespace geometry {\n  // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_B\n\
    \  bool is_convex_polygon(const Polygon &p) {\n    int n = (int)p.size();\n  \
    \  for (int i = 0; i < n; i++) {\n      if (ccw(p[(i + n - 1) % n], p[i], p[(i\
    \ + 1) % n]) == CLOCKWISE)\n        return false;\n    }\n    return true;\n \
    \ }\n} // namespace geometry\n"
  dependsOn:
  - geometry/ccw.hpp
  - geometry/point.hpp
  - geometry/base.hpp
  - geometry/polygon.hpp
  isVerificationFile: false
  path: geometry/is_convex_polygon.hpp
  requiredBy: []
  timestamp: '2022-08-27 15:55:50+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/verify/aoj-cgl-3-b.test.cpp
documentation_of: geometry/is_convex_polygon.hpp
layout: document
redirect_from:
- /library/geometry/is_convex_polygon.hpp
- /library/geometry/is_convex_polygon.hpp.html
title: geometry/is_convex_polygon.hpp
---
