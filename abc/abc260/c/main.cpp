#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, x, y;
  cin >> n >> x >> y;

  // map<P, ll> memo;
  // color == 1 → 赤
  // color == 2 → 青
  ll cnt = 0;
  auto rec = [&] (auto rec, int color, int level) -> ll {
    cnt++;

    if (level == 1) {
      if (color == 1) return 0; else return 1;
    }

    // P p = pair(color, level);
    // if (memo.count(p)) return memo[p];

    if (color == 1) {
      // 赤
      return rec(rec, color, level-1) + rec(rec, 2, level) * (ll)x;
    }

    return rec(rec, 1, level-1) + rec(rec, 2, level-1) * (ll)y;
  };

  cout << rec(rec, 1, n) << endl;;
  cout << cnt << endl;
  return 0;
}