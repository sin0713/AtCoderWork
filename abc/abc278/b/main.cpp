#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

const int h_max = 23;
const int m_max = 59;

int main() {
  int h, m;
  cin >> h >> m;

  auto f = [&] (int h, int m) -> bool {
    int x = h % 10;
    int y = m / 10;
    h -= x; h += y;
    m -= 10*y; m += 10*x;

    return h <= h_max && m <= m_max;
  };

  while(!f(h, m)) {
    if (m < m_max) {
      m++;
    } else if (h < h_max) {
      h++; m = 0;
    } else {
      h = 0; m = 0;
    }
  }

  printf("%d %d\n", h, m);
  return 0;
}