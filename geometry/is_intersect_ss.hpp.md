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
    path: geometry/line.hpp
    title: geometry/line.hpp
  - icon: ':question:'
    path: geometry/point.hpp
    title: geometry/point.hpp
  - icon: ':x:'
    path: geometry/segment.hpp
    title: geometry/segment.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: geometry/distance_ss.hpp
    title: geometry/distance_ss.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/verify/aoj-cgl-2-b.test.cpp
    title: test/verify/aoj-cgl-2-b.test.cpp
  - icon: ':x:'
    path: test/verify/aoj-cgl-2-d.test.cpp
    title: test/verify/aoj-cgl-2-d.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
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
    \ < imag(b);\n  }\n\n  using Points = vector< Point >;\n}\n#line 3 \"geometry/ccw.hpp\"\
    \n\nnamespace geometry {\n  // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C\n\
    \  constexpr int COUNTER_CLOCKWISE = +1;\n  constexpr int CLOCKWISE = -1;\n  constexpr\
    \ int ONLINE_BACK = +2; // c-a-b\n  constexpr int ONLINE_FRONT = -2; // a-b-c\n\
    \  constexpr int ON_SEGMENT = 0; // a-c-b\n  int ccw(const Point &a, Point b,\
    \ Point c) {\n    b = b - a, c = c - a;\n    if(sign(cross(b, c)) == +1) return\
    \ COUNTER_CLOCKWISE;\n    if(sign(cross(b, c)) == -1) return CLOCKWISE;\n    if(sign(dot(b,\
    \ c)) == -1) return ONLINE_BACK;\n    if(norm(b) < norm(c)) return ONLINE_FRONT;\n\
    \    return ON_SEGMENT;\n  }\n}\n#line 3 \"geometry/line.hpp\"\n\nnamespace geometry\
    \ {\n  struct Line {\n    Point a, b;\n\n    Line() = default;\n\n    Line(const\
    \ Point &a, const Point &b) : a(a), b(b) {}\n\n    Line(const Real &A, const Real\
    \ &B, const Real &C) { // Ax+By=C\n      if(equals(A, 0)) {\n        assert(!equals(B,\
    \ 0));\n        a = Point(0, C / B);\n        b = Point(1, C / B);\n      } else\
    \ if(equals(B, 0)) {\n        a = Point(C / A, 0);\n        b = Point(C / A, 1);\n\
    \      } else {\n        a = Point(0, C / B);\n        b = Point(C / A, 0);\n\
    \      }\n    }\n\n    friend ostream &operator<<(ostream &os, Line &l) {\n  \
    \    return os << l.a << \" to \" << l.b;\n    }\n\n    friend istream &operator>>(istream\
    \ &is, Line &l) {\n      return is >> l.a >> l.b;\n    }\n  };\n\n  using Lines\
    \ = vector< Line >;\n}\n#line 3 \"geometry/segment.hpp\"\n\nnamespace geometry\
    \ {\n  struct Segment : Line {\n    Segment() = default;\n\n    using Line::Line;\n\
    \  };\n\n  using Segments = vector< Segment >;\n}\n#line 4 \"geometry/is_intersect_ss.hpp\"\
    \n\n\nnamespace geometry {\n  bool is_intersect_ss(const Segment &s, const Segment\
    \ &t) {\n    return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 &&\n        \
    \   ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;\n  }\n}\n"
  code: "#include \"point.hpp\"\n#include \"ccw.hpp\"\n#include \"segment.hpp\"\n\n\
    \nnamespace geometry {\n  bool is_intersect_ss(const Segment &s, const Segment\
    \ &t) {\n    return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 &&\n        \
    \   ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;\n  }\n}\n"
  dependsOn:
  - geometry/point.hpp
  - geometry/base.hpp
  - geometry/ccw.hpp
  - geometry/segment.hpp
  - geometry/line.hpp
  isVerificationFile: false
  path: geometry/is_intersect_ss.hpp
  requiredBy:
  - geometry/distance_ss.hpp
  timestamp: '2022-09-11 00:53:50+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/verify/aoj-cgl-2-b.test.cpp
  - test/verify/aoj-cgl-2-d.test.cpp
documentation_of: geometry/is_intersect_ss.hpp
layout: document
redirect_from:
- /library/geometry/is_intersect_ss.hpp
- /library/geometry/is_intersect_ss.hpp.html
title: geometry/is_intersect_ss.hpp
---
