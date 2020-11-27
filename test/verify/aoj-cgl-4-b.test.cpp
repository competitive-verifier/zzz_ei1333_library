#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_B"
#define ERROR 0.00000001

#include "../../template/template.cpp"

#include "../../geometry/convex_polygon_diameter.cpp"

using namespace geometry;

int main() {
  int N;
  cin >> N;
  Polygon p(N);
  for(int i = 0; i < N; i++) {
    cin >> p[i];
  }
  auto ret = convex_polygon_diameter(p);
  cout << abs(p[ret.first] - p[ret.second]) << "\n";
}
