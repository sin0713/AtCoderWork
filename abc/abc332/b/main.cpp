#include <vector>
#include <algorithm>
#include <iostream>
#include <atcoder/all>
#include <math.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF (1 << 30)

int main() {
  int k, g_max, m_max;
  cin >> k >> g_max >> m_max;

  int glass = 0;
  int mug = 0;
  int cnt = 0;
  while(cnt < k) {
    if (glass >= g_max) {
      glass = 0;
    } else if (mug == 0) {
      mug = m_max;
    } else {
      // グラスの空き容量
      int glass_margin = g_max - glass;
      if (glass_margin <= mug) {
        // グラスの空き容量 <= 現在のまぐカップ
        mug -= glass_margin;
        glass = g_max; 
      } else {
        glass += mug;
        mug = 0;
      }
    }

    cnt++;
  }

  cout << glass << " " << mug << endl;

  return 0;
}