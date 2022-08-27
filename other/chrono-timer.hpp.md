---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"other/chrono-timer.hpp\"\nstruct ChronoTimer {\n  chrono::high_resolution_clock::time_point\
    \ st;\n\n  ChronoTimer() {\n    reset();\n  }\n\n  void reset() {\n    st = chrono::high_resolution_clock::now();\n\
    \  }\n\n  chrono::milliseconds::rep elapsed() {\n    auto ed = chrono::high_resolution_clock::now();\n\
    \    return chrono::duration_cast< chrono::milliseconds >(ed - st)\n        .count();\n\
    \  }\n};\n"
  code: "struct ChronoTimer {\n  chrono::high_resolution_clock::time_point st;\n\n\
    \  ChronoTimer() {\n    reset();\n  }\n\n  void reset() {\n    st = chrono::high_resolution_clock::now();\n\
    \  }\n\n  chrono::milliseconds::rep elapsed() {\n    auto ed = chrono::high_resolution_clock::now();\n\
    \    return chrono::duration_cast< chrono::milliseconds >(ed - st)\n        .count();\n\
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: other/chrono-timer.hpp
  requiredBy: []
  timestamp: '2022-08-27 15:55:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/chrono-timer.hpp
layout: document
redirect_from:
- /library/other/chrono-timer.hpp
- /library/other/chrono-timer.hpp.html
title: other/chrono-timer.hpp
---
