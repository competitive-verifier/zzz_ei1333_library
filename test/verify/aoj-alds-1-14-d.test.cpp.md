---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../string/suffix-array.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_D\"\
    \n\n#include \"../../template/template.cpp\"\n\n#include \"../../string/suffix-array.cpp\"\
    \n\nint main() {\n  string S;\n  int Q;\n\n  cin >> S;\n  SuffixArray sa(S);\n\
    \  cin >> Q;\n  while(Q--) {\n    string T;\n    cin >> T;\n    auto range = sa.lower_upper_bound(T);\n\
    \    cout << (range.first != range.second) << endl;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/verify/aoj-alds-1-14-d.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/verify/aoj-alds-1-14-d.test.cpp
layout: document
redirect_from:
- /verify/test/verify/aoj-alds-1-14-d.test.cpp
- /verify/test/verify/aoj-alds-1-14-d.test.cpp.html
title: test/verify/aoj-alds-1-14-d.test.cpp
---
