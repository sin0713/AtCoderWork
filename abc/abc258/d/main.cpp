#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, x;
  cin >> n >> x;
  vector<ll> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];

  ll ans = 2e18;
  ll sum = 0; // Ai + Bi の合計
  ll l = 1e18;// Biの最小値 

  rep(i, n) {
    sum += a[i] + b[i];
    l = min(l, b[i]);

    if (x-i-1 < 0) break;

    ll now = sum + l*(x-i-1);
    ans = min(ans, now);
  }

  cout << ans << endl;
  return 0;
}