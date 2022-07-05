---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/verify/yosupo-enumerate-palindromes.test.cpp
    title: test/verify/yosupo-enumerate-palindromes.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "Manacher(\u6700\u9577\u56DE\u6587)"
    links: []
  bundledCode: "#line 1 \"string/manacher.hpp\"\n/**\n * @brief Manacher(\u6700\u9577\
    \u56DE\u6587)\n */\ntemplate< typename S >\nvector< int > manacher(S s, bool calc_even\
    \ = true) {\n  if(calc_even) {\n    int n = (int) s.size();\n    assert(n > 0);\n\
    \    s.resize(2 * n - 1);\n    for(int i = n - 1; i >= 0; i--) {\n      s[2 *\
    \ i] = s[i];\n    }\n    auto d = *min_element(begin(s), end(s));\n    for(int\
    \ i = 0; i < n - 1; i++) {\n      s[2 * i + 1] = d;\n    }\n  }\n  int n = (int)\
    \ s.size();\n  vector< int > rad(n);\n  {\n    int i = 0, j = 0;\n    while(i\
    \ < n) {\n      while(i - j >= 0 && i + j < n && s[i - j] == s[i + j]) ++j;\n\
    \      rad[i] = j;\n      int k = 1;\n      while(i - k >= 0 && i + k < n && k\
    \ + rad[i - k] < j) {\n        rad[i + k] = rad[i - k];\n        ++k;\n      }\n\
    \      i += k, j -= k;\n    }\n  }\n  if(calc_even) {\n    for(int i = 0; i <\
    \ n; i++) {\n      if(((i ^ rad[i]) & 1) == 0) rad[i]--;\n    }\n  } else {\n\
    \    for(auto &&x: rad) x = 2 * x - 1;\n  }\n  return rad;\n}\n"
  code: "/**\n * @brief Manacher(\u6700\u9577\u56DE\u6587)\n */\ntemplate< typename\
    \ S >\nvector< int > manacher(S s, bool calc_even = true) {\n  if(calc_even) {\n\
    \    int n = (int) s.size();\n    assert(n > 0);\n    s.resize(2 * n - 1);\n \
    \   for(int i = n - 1; i >= 0; i--) {\n      s[2 * i] = s[i];\n    }\n    auto\
    \ d = *min_element(begin(s), end(s));\n    for(int i = 0; i < n - 1; i++) {\n\
    \      s[2 * i + 1] = d;\n    }\n  }\n  int n = (int) s.size();\n  vector< int\
    \ > rad(n);\n  {\n    int i = 0, j = 0;\n    while(i < n) {\n      while(i - j\
    \ >= 0 && i + j < n && s[i - j] == s[i + j]) ++j;\n      rad[i] = j;\n      int\
    \ k = 1;\n      while(i - k >= 0 && i + k < n && k + rad[i - k] < j) {\n     \
    \   rad[i + k] = rad[i - k];\n        ++k;\n      }\n      i += k, j -= k;\n \
    \   }\n  }\n  if(calc_even) {\n    for(int i = 0; i < n; i++) {\n      if(((i\
    \ ^ rad[i]) & 1) == 0) rad[i]--;\n    }\n  } else {\n    for(auto &&x: rad) x\
    \ = 2 * x - 1;\n  }\n  return rad;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: string/manacher.hpp
  requiredBy: []
  timestamp: '2022-03-30 22:35:09+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/verify/yosupo-enumerate-palindromes.test.cpp
documentation_of: string/manacher.hpp
layout: document
redirect_from:
- /library/string/manacher.hpp
- /library/string/manacher.hpp.html
title: "Manacher(\u6700\u9577\u56DE\u6587)"
---
