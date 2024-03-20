#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n, m;
  cin >> n >> m;

  const ll INF = 1e18;
  ll ans = INF;
  for (ll a = 1; a*a - a < m+1; a++) {

    ll b = (m+a-1) / a;
    // cout << "a=" << a << " b=" << b << endl;
    if (a <= n && b <= n) {
      ans = min(ans, a*b);
    }
  }

  if (ans == INF) cout << -1 << endl;
  else cout << ans << endl;
  return 0;
}