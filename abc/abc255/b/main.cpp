#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, k;
  cin >> n >> k;

  vector<bool> has_light(n, false);
  rep(i, k) {
    int x; cin >> x; x--;
    has_light[x] = true;
  }

  vector<int> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];

  const ll INF = 1e18;
  ll res = 0;
  rep(i, n) {
    if (has_light[i]) continue;

    ll now = INF;
    rep(j, n) {
      if (!has_light[j]) continue;

      ll dy = y[i]-y[j];
      ll dx = x[i]-x[j];
      ll dist = dy*dy + dx*dx;
      now = min(now, dist);
    }

    res = max(res, now);
  }

  double ans = sqrt(res);
  printf("%.10f\n", ans);
  return 0;
}