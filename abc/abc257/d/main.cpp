#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> x(n), y(n), p(n);
  rep(i, n) cin >> x[i] >> y[i] >> p[i];

  auto judge = [&] (ll jump) -> bool {
    vector<vector<int>> d(n, vector<int>(n));
    rep(i, n) {
      rep(j, n) {
        ll dist = (ll)abs(x[i]-x[j])+abs(y[i]-y[j]);
        if (jump*p[i] >= dist) d[i][j] = 1;
      }
    }

    // ワーシャルフロイド
    // 頂点kを経由して頂点iから頂点jにたどり着けるか
    rep(k, n) {
      rep(i, n) {
        rep(j, n) {
          d[i][j] |= d[i][k]&d[k][j];
        }
      }
    }

    // 最終的に頂点iから頂点jににたどり着けるようになっているか判定
    rep(i, n) {
      bool ok = true;
      rep(j, n) {
        if (d[i][j] == 0) ok = false;
      }
      if (ok) return true;
    }
    return false;
  };

  // 二分探索
  ll wa = 0, ac = 4e9;
  while(ac-wa > 1) {
    ll wj = (ac+wa) / 2;
    if (judge(wj)) ac = wj; else wa = wj;
  }

  cout << ac << endl;
  return 0;
}