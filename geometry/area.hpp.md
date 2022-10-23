---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: geometry/base.hpp
    title: geometry/base.hpp
  - icon: ':question:'
    path: geometry/point.hpp
    title: geometry/point.hpp
  - icon: ':question:'
    path: geometry/polygon.hpp
    title: geometry/polygon.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/verify/aoj-cgl-3-a.test.cpp
    title: test/verify/aoj-cgl-3-a.test.cpp
  - icon: ':x:'
    path: test/verify/aoj-cgl-4-c.test.cpp
    title: test/verify/aoj-cgl-4-c.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A
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
    \ = vector< Point >;\n  using Polygons = vector< Polygon >;\n}\n#line 3 \"geometry/area.hpp\"\
    \n\nnamespace geometry {\n  // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A\n\
    \  Real area(const Polygon &p) {\n    int n = (int) p.size();\n    Real A = 0;\n\
    \    for(int i = 0; i < n; ++i) {\n      A += cross(p[i], p[(i + 1) % n]);\n \
    \   }\n    return A * 0.5;\n  }\n}\n"
  code: "#include \"point.hpp\"\n#include \"polygon.hpp\"\n\nnamespace geometry {\n\
    \  // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A\n  Real\
    \ area(const Polygon &p) {\n    int n = (int) p.size();\n    Real A = 0;\n   \
    \ for(int i = 0; i < n; ++i) {\n      A += cross(p[i], p[(i + 1) % n]);\n    }\n\
    \    return A * 0.5;\n  }\n}\n"
  dependsOn:
  - geometry/point.hpp
  - geometry/base.hpp
  - geometry/polygon.hpp
  isVerificationFile: false
  path: geometry/area.hpp
  requiredBy: []
  timestamp: '2022-09-11 00:53:50+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/verify/aoj-cgl-4-c.test.cpp
  - test/verify/aoj-cgl-3-a.test.cpp
documentation_of: geometry/area.hpp
layout: document
redirect_from:
- /library/geometry/area.hpp
- /library/geometry/area.hpp.html
title: geometry/area.hpp
---
