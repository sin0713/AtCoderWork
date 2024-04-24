#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int a, b, d;
  cin >> a >> b >> d;

  // theta と 半径rをもとめる
  double theta = atan2(b, a);
  double r = sqrt(a*a + b*b);

  // x = cos(theta+d)
  // y = sin(theta+d)
  theta += d/180.0 * acos(-1);
  double x = cos(theta) * r;
  double y = sin(theta) * r;
  printf("%.10f %.10f", x, y);
  return 0;
}