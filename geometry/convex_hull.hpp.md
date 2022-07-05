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
    path: test/verify/aoj-cgl-4-a.test.cpp
    title: test/verify/aoj-cgl-4-a.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A
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
    \ = vector< Point >;\n  using Polygons = vector< Polygon >;\n}\n#line 4 \"geometry/convex_hull.hpp\"\
    \n\nnamespace geometry {\n  // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A\n\
    \  Polygon convex_hull(Polygon &p, bool strict = true) {\n    int n = (int) p.size(),\
    \ k = 0;\n    if(n <= 2) return p;\n    sort(begin(p), end(p), compare_x);\n \
    \   vector< Point > ch(2 * n);\n    auto check = [&](int i) {\n      return sign(cross(ch[k\
    \ - 1] - ch[k - 2], p[i] - ch[k - 1])) <= -1 + strict;\n    };\n    for(int i\
    \ = 0; i < n; ch[k++] = p[i++]) {\n      while(k >= 2 && check(i)) --k;\n    }\n\
    \    for(int i = n - 2, t = k + 1; i >= 0; ch[k++] = p[i--]) {\n      while(k\
    \ >= t && check(i)) --k;\n    }\n    ch.resize(k - 1);\n    return ch;\n  }\n\
    }\n"
  code: "#include \"base.hpp\"\n#include \"point.hpp\"\n#include \"polygon.hpp\"\n\
    \nnamespace geometry {\n  // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A\n\
    \  Polygon convex_hull(Polygon &p, bool strict = true) {\n    int n = (int) p.size(),\
    \ k = 0;\n    if(n <= 2) return p;\n    sort(begin(p), end(p), compare_x);\n \
    \   vector< Point > ch(2 * n);\n    auto check = [&](int i) {\n      return sign(cross(ch[k\
    \ - 1] - ch[k - 2], p[i] - ch[k - 1])) <= -1 + strict;\n    };\n    for(int i\
    \ = 0; i < n; ch[k++] = p[i++]) {\n      while(k >= 2 && check(i)) --k;\n    }\n\
    \    for(int i = n - 2, t = k + 1; i >= 0; ch[k++] = p[i--]) {\n      while(k\
    \ >= t && check(i)) --k;\n    }\n    ch.resize(k - 1);\n    return ch;\n  }\n\
    }\n"
  dependsOn:
  - geometry/base.hpp
  - geometry/point.hpp
  - geometry/polygon.hpp
  isVerificationFile: false
  path: geometry/convex_hull.hpp
  requiredBy: []
  timestamp: '2022-07-05 18:16:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/verify/aoj-cgl-4-a.test.cpp
documentation_of: geometry/convex_hull.hpp
layout: document
redirect_from:
- /library/geometry/convex_hull.hpp
- /library/geometry/convex_hull.hpp.html
title: geometry/convex_hull.hpp
---
