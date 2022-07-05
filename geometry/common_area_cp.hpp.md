---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/base.hpp
    title: geometry/base.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/ccw.hpp
    title: geometry/ccw.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/circle.hpp
    title: geometry/circle.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/cross_point_cl.hpp
    title: geometry/cross_point_cl.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/distance_sp.hpp
    title: geometry/distance_sp.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/is_intersect_cs.hpp
    title: geometry/is_intersect_cs.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/is_intersect_sp.hpp
    title: geometry/is_intersect_sp.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/line.hpp
    title: geometry/line.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/point.hpp
    title: geometry/point.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/polygon.hpp
    title: geometry/polygon.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/projection.hpp
    title: geometry/projection.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/segment.hpp
    title: geometry/segment.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj-cgl-7-h.test.cpp
    title: test/verify/aoj-cgl-7-h.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_H
  bundledCode: "#line 2 \"geometry/base.hpp\"\n\nnamespace geometry {\n  using Real\
    \ = double;\n  const Real EPS = 1e-8;\n  const Real PI = acos(static_cast< Real\
    \ >(-1));\n\n  enum {\n    OUT, ON, IN\n  };\n\n  inline int sign(const Real &r)\
    \ {\n    return r <= -EPS ? -1 : r >= EPS ? 1 : 0;\n  }\n\n  inline bool equals(const\
    \ Real &a, const Real &b) {\n    return sign(a - b) == 0;\n  }\n}\n#line 3 \"\
    geometry/point.hpp\"\n\nnamespace geometry {\n  using Point = complex< Real >;\n\
    \n  istream &operator>>(istream &is, Point &p) {\n    Real a, b;\n    is >> a\
    \ >> b;\n    p = Point(a, b);\n    return is;\n  }\n\n  ostream &operator<<(ostream\
    \ &os, const Point &p) {\n    return os << real(p) << \" \" << imag(p);\n  }\n\
    \n  Point operator*(const Point &p, const Real &d) {\n    return Point(real(p)\
    \ * d, imag(p) * d);\n  }\n\n  // rotate point p counterclockwise by theta rad\n\
    \  Point rotate(Real theta, const Point &p) {\n    return Point(cos(theta) * real(p)\
    \ - sin(theta) * imag(p), sin(theta) * real(p) + cos(theta) * imag(p));\n  }\n\
    \n  Real cross(const Point &a, const Point &b) {\n    return real(a) * imag(b)\
    \ - imag(a) * real(b);\n  }\n\n  Real dot(const Point &a, const Point &b) {\n\
    \    return real(a) * real(b) + imag(a) * imag(b);\n  }\n\n  bool compare_x(const\
    \ Point &a, const Point &b) {\n    return equals(real(a), real(b)) ? imag(a) <\
    \ imag(b) : real(a) < real(b);\n  }\n\n  bool compare_y(const Point &a, const\
    \ Point &b) {\n    return equals(imag(a), imag(b)) ? real(a) < real(b) : imag(a)\
    \ < imag(b);\n  }\n\n  using Points = vector< Point >;\n}\n#line 2 \"geometry/polygon.hpp\"\
    \n\n#line 4 \"geometry/polygon.hpp\"\n\nnamespace geometry {\n  using Polygon\
    \ = vector< Point >;\n  using Polygons = vector< Polygon >;\n}\n#line 3 \"geometry/line.hpp\"\
    \n\nnamespace geometry {\n  struct Line {\n    Point a, b;\n\n    Line() = default;\n\
    \n    Line(const Point &a, const Point &b) : a(a), b(b) {}\n\n    Line(const Real\
    \ &A, const Real &B, const Real &C) { // Ax+By=C\n      if(equals(A, 0)) {\n \
    \       assert(!equals(B, 0));\n        a = Point(0, C / B);\n        b = Point(1,\
    \ C / B);\n      } else if(equals(B, 0)) {\n        a = Point(C / A, 0);\n   \
    \     b = Point(C / A, 1);\n      } else {\n        a = Point(0, C / B);\n   \
    \     b = Point(C / A, 0);\n      }\n    }\n\n    friend ostream &operator<<(ostream\
    \ &os, Line &l) {\n      return os << l.a << \" to \" << l.b;\n    }\n\n    friend\
    \ istream &operator>>(istream &is, Line &l) {\n      return is >> l.a >> l.b;\n\
    \    }\n  };\n\n  using Lines = vector< Line >;\n}\n#line 3 \"geometry/segment.hpp\"\
    \n\nnamespace geometry {\n  struct Segment : Line {\n    Segment() = default;\n\
    \n    using Line::Line;\n  };\n\n  using Segments = vector< Segment >;\n}\n#line\
    \ 2 \"geometry/projection.hpp\"\n\n#line 5 \"geometry/projection.hpp\"\n\nnamespace\
    \ geometry {\n  // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A\n\
    \  Point projection(const Line &l, const Point &p) {\n    auto t = dot(p - l.a,\
    \ l.a - l.b) / norm(l.a - l.b);\n    return l.a + (l.a - l.b) * t;\n  }\n}\n#line\
    \ 3 \"geometry/ccw.hpp\"\n\nnamespace geometry {\n  // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C\n\
    \  constexpr int COUNTER_CLOCKWISE = +1;\n  constexpr int CLOCKWISE = -1;\n  constexpr\
    \ int ONLINE_BACK = +2; // c-a-b\n  constexpr int ONLINE_FRONT = -2; // a-b-c\n\
    \  constexpr int ON_SEGMENT = 0; // a-c-b\n  int ccw(const Point &a, Point b,\
    \ Point c) {\n    b = b - a, c = c - a;\n    if(sign(cross(b, c)) == +1) return\
    \ COUNTER_CLOCKWISE;\n    if(sign(cross(b, c)) == -1) return CLOCKWISE;\n    if(sign(dot(b,\
    \ c)) == -1) return ONLINE_BACK;\n    if(norm(b) < norm(c)) return ONLINE_FRONT;\n\
    \    return ON_SEGMENT;\n  }\n}\n#line 4 \"geometry/is_intersect_sp.hpp\"\n\n\
    namespace geometry {\n  bool is_intersect_sp(const Segment &s, const Point &p)\
    \ {\n    return ccw(s.a, s.b, p) == ON_SEGMENT;\n  }\n}\n#line 5 \"geometry/distance_sp.hpp\"\
    \n\nnamespace geometry {\n  Real distance_sp(const Segment &s, const Point &p)\
    \ {\n    Point r = projection(s, p);\n    if(is_intersect_sp(s, r)) return abs(r\
    \ - p);\n    return min(abs(s.a - p), abs(s.b - p));\n  }\n}\n#line 3 \"geometry/circle.hpp\"\
    \n\nnamespace geometry {\n  struct Circle {\n    Point p;\n    Real r{};\n\n \
    \   Circle() = default;\n\n    Circle(const Point &p, const Real &r) : p(p), r(r)\
    \ {}\n  };\n\n  using Circles = vector< Circle >;\n}\n#line 6 \"geometry/cross_point_cl.hpp\"\
    \n\nnamespace geometry {\n  // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D\n\
    \  Points cross_point_cl(const Circle &c, const Line &l) {\n    Point pr = projection(l,\
    \ c.p);\n    if(equals(abs(pr - c.p), c.r)) return {pr};\n    Point e = (l.b -\
    \ l.a) / abs(l.b - l.a);\n    auto k = sqrt(norm(c.r) - norm(pr - c.p));\n   \
    \ return {pr - e * k, pr + e * k};\n  }\n}\n#line 6 \"geometry/is_intersect_cs.hpp\"\
    \n\nnamespace geometry {\n  int is_intersect_cs(const Circle &c, const Segment\
    \ &l) {\n    Point h = projection(l, c.p);\n    if(sign(norm(h - c.p) - norm(c.r))\
    \ > 0) return 0;\n    auto d1 = abs(c.p - l.a), d2 = abs(c.p - l.b);\n    if(sign(c.r\
    \ - d1) >= 0 && sign(c.r - d2) >= 0) return 0;\n    if(sign(c.r - d1) < 0 && sign(d2\
    \ - c.r) > 0 || sign(d1 - c.r) > 0 && sign(c.r - d2) < 0) return 1;\n    if(sign(dot(l.a\
    \ - h, l.b - h)) < 0) return 2;\n    return 0;\n  }\n}\n#line 7 \"geometry/common_area_cp.hpp\"\
    \n\nnamespace geometry {\n  // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_H\n\
    \  Real ca_cp_impl(const Circle &c, const Point &a, const Point &b) {\n    auto\
    \ va = c.p - a, vb = c.p - b;\n    Real f = cross(va, vb), ret = 0;\n    if(sign(f)\
    \ == 0) return ret;\n    if(sign(max(abs(va), abs(vb)) - c.r) <= 0) return f;\n\
    \    if(sign(distance_sp(Segment(a, b), c.p) - c.r) >= 0) return norm(c.r) * arg(vb\
    \ * conj(va));\n    auto tot = cross_point_cl(c, Line(a, b));\n    if(is_intersect_cs(c,\
    \ Segment(a, b)) != 2 and dot(a - tot[0], b - tot[0]) < 0) {\n      swap(tot[0],\
    \ tot[1]);\n    }\n    tot.emplace(begin(tot), a);\n    tot.emplace_back(b);\n\
    \    for(int i = 1; i < (int) tot.size(); i++) {\n      ret += ca_cp_impl(c, tot[i\
    \ - 1], tot[i]);\n    }\n    return ret;\n  }\n\n  Real common_area_cp(const Circle\
    \ &c, const Polygon &p) {\n    if(p.size() < 3) return 0;\n    Real A = 0;\n \
    \   for(int i = 0; i < p.size(); i++) {\n      A += ca_cp_impl(c, p[i], p[(i +\
    \ 1) % p.size()]);\n    }\n    return A * 0.5;\n  }\n}\n"
  code: "#include \"base.hpp\"\n#include \"point.hpp\"\n#include \"polygon.hpp\"\n\
    #include \"distance_sp.hpp\"\n#include \"cross_point_cl.hpp\"\n#include \"is_intersect_cs.hpp\"\
    \n\nnamespace geometry {\n  // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_H\n\
    \  Real ca_cp_impl(const Circle &c, const Point &a, const Point &b) {\n    auto\
    \ va = c.p - a, vb = c.p - b;\n    Real f = cross(va, vb), ret = 0;\n    if(sign(f)\
    \ == 0) return ret;\n    if(sign(max(abs(va), abs(vb)) - c.r) <= 0) return f;\n\
    \    if(sign(distance_sp(Segment(a, b), c.p) - c.r) >= 0) return norm(c.r) * arg(vb\
    \ * conj(va));\n    auto tot = cross_point_cl(c, Line(a, b));\n    if(is_intersect_cs(c,\
    \ Segment(a, b)) != 2 and dot(a - tot[0], b - tot[0]) < 0) {\n      swap(tot[0],\
    \ tot[1]);\n    }\n    tot.emplace(begin(tot), a);\n    tot.emplace_back(b);\n\
    \    for(int i = 1; i < (int) tot.size(); i++) {\n      ret += ca_cp_impl(c, tot[i\
    \ - 1], tot[i]);\n    }\n    return ret;\n  }\n\n  Real common_area_cp(const Circle\
    \ &c, const Polygon &p) {\n    if(p.size() < 3) return 0;\n    Real A = 0;\n \
    \   for(int i = 0; i < p.size(); i++) {\n      A += ca_cp_impl(c, p[i], p[(i +\
    \ 1) % p.size()]);\n    }\n    return A * 0.5;\n  }\n}\n"
  dependsOn:
  - geometry/base.hpp
  - geometry/point.hpp
  - geometry/polygon.hpp
  - geometry/distance_sp.hpp
  - geometry/segment.hpp
  - geometry/line.hpp
  - geometry/projection.hpp
  - geometry/is_intersect_sp.hpp
  - geometry/ccw.hpp
  - geometry/cross_point_cl.hpp
  - geometry/circle.hpp
  - geometry/is_intersect_cs.hpp
  isVerificationFile: false
  path: geometry/common_area_cp.hpp
  requiredBy: []
  timestamp: '2022-07-05 18:16:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/aoj-cgl-7-h.test.cpp
documentation_of: geometry/common_area_cp.hpp
layout: document
redirect_from:
- /library/geometry/common_area_cp.hpp
- /library/geometry/common_area_cp.hpp.html
title: geometry/common_area_cp.hpp
---
