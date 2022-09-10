---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: geometry/base.hpp
    title: geometry/base.hpp
  - icon: ':x:'
    path: geometry/ccw.hpp
    title: geometry/ccw.hpp
  - icon: ':x:'
    path: geometry/distance_sp.hpp
    title: geometry/distance_sp.hpp
  - icon: ':x:'
    path: geometry/is_intersect_sp.hpp
    title: geometry/is_intersect_sp.hpp
  - icon: ':x:'
    path: geometry/is_intersect_ss.hpp
    title: geometry/is_intersect_ss.hpp
  - icon: ':x:'
    path: geometry/line.hpp
    title: geometry/line.hpp
  - icon: ':question:'
    path: geometry/point.hpp
    title: geometry/point.hpp
  - icon: ':x:'
    path: geometry/projection.hpp
    title: geometry/projection.hpp
  - icon: ':x:'
    path: geometry/segment.hpp
    title: geometry/segment.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/verify/aoj-cgl-2-d.test.cpp
    title: test/verify/aoj-cgl-2-d.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D
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
    \ < imag(b);\n  }\n\n  using Points = vector< Point >;\n}\n#line 3 \"geometry/line.hpp\"\
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
    \ 3 \"geometry/ccw.hpp\"\n\nnamespace geometry {\n  // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C\n\
    \  constexpr int COUNTER_CLOCKWISE = +1;\n  constexpr int CLOCKWISE = -1;\n  constexpr\
    \ int ONLINE_BACK = +2; // c-a-b\n  constexpr int ONLINE_FRONT = -2; // a-b-c\n\
    \  constexpr int ON_SEGMENT = 0; // a-c-b\n  int ccw(const Point &a, Point b,\
    \ Point c) {\n    b = b - a, c = c - a;\n    if(sign(cross(b, c)) == +1) return\
    \ COUNTER_CLOCKWISE;\n    if(sign(cross(b, c)) == -1) return CLOCKWISE;\n    if(sign(dot(b,\
    \ c)) == -1) return ONLINE_BACK;\n    if(norm(b) < norm(c)) return ONLINE_FRONT;\n\
    \    return ON_SEGMENT;\n  }\n}\n#line 4 \"geometry/is_intersect_ss.hpp\"\n\n\n\
    namespace geometry {\n  bool is_intersect_ss(const Segment &s, const Segment &t)\
    \ {\n    return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 &&\n           ccw(t.a,\
    \ t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;\n  }\n}\n#line 2 \"geometry/projection.hpp\"\
    \n\n#line 5 \"geometry/projection.hpp\"\n\nnamespace geometry {\n  // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A\n\
    \  Point projection(const Line &l, const Point &p) {\n    auto t = dot(p - l.a,\
    \ l.a - l.b) / norm(l.a - l.b);\n    return l.a + (l.a - l.b) * t;\n  }\n}\n#line\
    \ 4 \"geometry/is_intersect_sp.hpp\"\n\nnamespace geometry {\n  bool is_intersect_sp(const\
    \ Segment &s, const Point &p) {\n    return ccw(s.a, s.b, p) == ON_SEGMENT;\n\
    \  }\n}\n#line 5 \"geometry/distance_sp.hpp\"\n\nnamespace geometry {\n  Real\
    \ distance_sp(const Segment &s, const Point &p) {\n    Point r = projection(s,\
    \ p);\n    if(is_intersect_sp(s, r)) return abs(r - p);\n    return min(abs(s.a\
    \ - p), abs(s.b - p));\n  }\n}\n#line 4 \"geometry/distance_ss.hpp\"\n\nnamespace\
    \ geometry {\n  // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D\n\
    \  Real distance_ss(const Segment &a, const Segment &b) {\n    if(is_intersect_ss(a,\
    \ b)) return 0;\n    return min({distance_sp(a, b.a), distance_sp(a, b.b), distance_sp(b,\
    \ a.a), distance_sp(b, a.b)});\n  }\n}\n\n"
  code: "#include \"segment.hpp\"\n#include \"is_intersect_ss.hpp\"\n#include \"distance_sp.hpp\"\
    \n\nnamespace geometry {\n  // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D\n\
    \  Real distance_ss(const Segment &a, const Segment &b) {\n    if(is_intersect_ss(a,\
    \ b)) return 0;\n    return min({distance_sp(a, b.a), distance_sp(a, b.b), distance_sp(b,\
    \ a.a), distance_sp(b, a.b)});\n  }\n}\n\n"
  dependsOn:
  - geometry/segment.hpp
  - geometry/line.hpp
  - geometry/point.hpp
  - geometry/base.hpp
  - geometry/is_intersect_ss.hpp
  - geometry/ccw.hpp
  - geometry/distance_sp.hpp
  - geometry/projection.hpp
  - geometry/is_intersect_sp.hpp
  isVerificationFile: false
  path: geometry/distance_ss.hpp
  requiredBy: []
  timestamp: '2022-09-11 00:53:50+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/verify/aoj-cgl-2-d.test.cpp
documentation_of: geometry/distance_ss.hpp
layout: document
redirect_from:
- /library/geometry/distance_ss.hpp
- /library/geometry/distance_ss.hpp.html
title: geometry/distance_ss.hpp
---
