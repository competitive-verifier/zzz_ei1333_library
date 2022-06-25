---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/base.cpp
    title: geometry/base.cpp
  - icon: ':heavy_check_mark:'
    path: geometry/line.cpp
    title: geometry/line.cpp
  - icon: ':heavy_check_mark:'
    path: geometry/point.cpp
    title: geometry/point.cpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: geometry/common_area_cp.cpp
    title: geometry/common_area_cp.cpp
  - icon: ':heavy_check_mark:'
    path: geometry/cross_point_cl.cpp
    title: geometry/cross_point_cl.cpp
  - icon: ':warning:'
    path: geometry/cross_point_cs.cpp
    title: geometry/cross_point_cs.cpp
  - icon: ':warning:'
    path: geometry/distance_ll.cpp
    title: geometry/distance_ll.cpp
  - icon: ':warning:'
    path: geometry/distance_lp.cpp
    title: geometry/distance_lp.cpp
  - icon: ':heavy_check_mark:'
    path: geometry/distance_sp.cpp
    title: geometry/distance_sp.cpp
  - icon: ':heavy_check_mark:'
    path: geometry/distance_ss.cpp
    title: geometry/distance_ss.cpp
  - icon: ':warning:'
    path: geometry/is_intersect_cl.cpp
    title: geometry/is_intersect_cl.cpp
  - icon: ':heavy_check_mark:'
    path: geometry/is_intersect_cs.cpp
    title: geometry/is_intersect_cs.cpp
  - icon: ':heavy_check_mark:'
    path: geometry/reflection.cpp
    title: geometry/reflection.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj-cgl-1-a.test.cpp
    title: test/verify/aoj-cgl-1-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj-cgl-1-b.test.cpp
    title: test/verify/aoj-cgl-1-b.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj-cgl-2-d.test.cpp
    title: test/verify/aoj-cgl-2-d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj-cgl-7-d.test.cpp
    title: test/verify/aoj-cgl-7-d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj-cgl-7-h.test.cpp
    title: test/verify/aoj-cgl-7-h.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A
  bundledCode: "#line 2 \"geometry/projection.cpp\"\n\n#line 2 \"geometry/base.cpp\"\
    \n\nnamespace geometry {\n  using Real = double;\n  const Real EPS = 1e-8;\n \
    \ const Real PI = acos(static_cast< Real >(-1));\n\n  enum {\n    OUT, ON, IN\n\
    \  };\n\n  inline int sign(const Real &r) {\n    return r <= -EPS ? -1 : r >=\
    \ EPS ? 1 : 0;\n  }\n\n  inline bool equals(const Real &a, const Real &b) {\n\
    \    return sign(a - b) == 0;\n  }\n}\n#line 3 \"geometry/point.cpp\"\n\nnamespace\
    \ geometry {\n  using Point = complex< Real >;\n\n  istream &operator>>(istream\
    \ &is, Point &p) {\n    Real a, b;\n    is >> a >> b;\n    p = Point(a, b);\n\
    \    return is;\n  }\n\n  ostream &operator<<(ostream &os, const Point &p) {\n\
    \    return os << real(p) << \" \" << imag(p);\n  }\n\n  Point operator*(const\
    \ Point &p, const Real &d) {\n    return Point(real(p) * d, imag(p) * d);\n  }\n\
    \n  // rotate point p counterclockwise by theta rad\n  Point rotate(Real theta,\
    \ const Point &p) {\n    return Point(cos(theta) * real(p) - sin(theta) * imag(p),\
    \ sin(theta) * real(p) + cos(theta) * imag(p));\n  }\n\n  Real cross(const Point\
    \ &a, const Point &b) {\n    return real(a) * imag(b) - imag(a) * real(b);\n \
    \ }\n\n  Real dot(const Point &a, const Point &b) {\n    return real(a) * real(b)\
    \ + imag(a) * imag(b);\n  }\n\n  bool compare_x(const Point &a, const Point &b)\
    \ {\n    return equals(real(a), real(b)) ? imag(a) < imag(b) : real(a) < real(b);\n\
    \  }\n\n  bool compare_y(const Point &a, const Point &b) {\n    return equals(imag(a),\
    \ imag(b)) ? real(a) < real(b) : imag(a) < imag(b);\n  }\n\n  using Points = vector<\
    \ Point >;\n}\n#line 3 \"geometry/line.cpp\"\n\nnamespace geometry {\n  struct\
    \ Line {\n    Point a, b;\n\n    Line() = default;\n\n    Line(const Point &a,\
    \ const Point &b) : a(a), b(b) {}\n\n    Line(const Real &A, const Real &B, const\
    \ Real &C) { // Ax+By=C\n      if(equals(A, 0)) {\n        assert(!equals(B, 0));\n\
    \        a = Point(0, C / B);\n        b = Point(1, C / B);\n      } else if(equals(B,\
    \ 0)) {\n        a = Point(C / A, 0);\n        b = Point(C / A, 1);\n      } else\
    \ {\n        a = Point(0, C / B);\n        b = Point(C / A, 0);\n      }\n   \
    \ }\n\n    friend ostream &operator<<(ostream &os, Line &l) {\n      return os\
    \ << l.a << \" to \" << l.b;\n    }\n\n    friend istream &operator>>(istream\
    \ &is, Line &l) {\n      return is >> l.a >> l.b;\n    }\n  };\n\n  using Lines\
    \ = vector< Line >;\n}\n#line 5 \"geometry/projection.cpp\"\n\nnamespace geometry\
    \ {\n  // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A\n \
    \ Point projection(const Line &l, const Point &p) {\n    auto t = dot(p - l.a,\
    \ l.a - l.b) / norm(l.a - l.b);\n    return l.a + (l.a - l.b) * t;\n  }\n}\n"
  code: "#pragma once\n\n#include \"point.cpp\"\n#include \"line.cpp\"\n\nnamespace\
    \ geometry {\n  // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A\n\
    \  Point projection(const Line &l, const Point &p) {\n    auto t = dot(p - l.a,\
    \ l.a - l.b) / norm(l.a - l.b);\n    return l.a + (l.a - l.b) * t;\n  }\n}\n"
  dependsOn:
  - geometry/point.cpp
  - geometry/base.cpp
  - geometry/line.cpp
  isVerificationFile: false
  path: geometry/projection.cpp
  requiredBy:
  - geometry/distance_lp.cpp
  - geometry/is_intersect_cs.cpp
  - geometry/cross_point_cl.cpp
  - geometry/cross_point_cs.cpp
  - geometry/distance_ss.cpp
  - geometry/distance_ll.cpp
  - geometry/is_intersect_cl.cpp
  - geometry/reflection.cpp
  - geometry/distance_sp.cpp
  - geometry/common_area_cp.cpp
  timestamp: '2020-12-01 18:35:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/aoj-cgl-7-d.test.cpp
  - test/verify/aoj-cgl-1-a.test.cpp
  - test/verify/aoj-cgl-2-d.test.cpp
  - test/verify/aoj-cgl-7-h.test.cpp
  - test/verify/aoj-cgl-1-b.test.cpp
documentation_of: geometry/projection.cpp
layout: document
redirect_from:
- /library/geometry/projection.cpp
- /library/geometry/projection.cpp.html
title: geometry/projection.cpp
---
