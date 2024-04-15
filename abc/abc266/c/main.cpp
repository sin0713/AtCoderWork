#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

struct V {
  int x, y;
  V(int x = 0, int y = 0): x(x), y(y) {};

  // 演算子オーバーロード
  V operator-(const V& a) {
    return V(x - a.x, y - a.y);
  }

  // 外積
  int cross(const V& a) const {
    return x*a.y - y*a.x;
  }

  // 反時計回りかの判定
  int ccw(const V& a) const {
    // 二つのベクトルに作られる平行四辺形
    int area = cross(a);
    if (area > 0) return 1; 
    if (area < 0) return -1; 
    return 0;
  }
};

int main() {
  vector<V> p(4);
  rep(i, 4) cin >> p[i].x >> p[i].y;

  rep(i, 4) {
    V A = p[i];
    V B = p[(i+1)%4];
    V C = p[(i+2)%4];
    V b = B - A;
    V c = C - A;
    if (b.ccw(c) != 1) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  return 0;
}