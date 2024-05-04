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
  vector<ll> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];

  ll initial = 0;
  rep(i, n) {
    if (i == (n-1)) {
      initial += b[i];
      continue;
    }

    initial += a[i];
  }

  ll ans = initial;
  rep(i, n-1) {
    ll b_diff = b[i] - b[n-1];
    ll a_diff = a[n-1] - a[i];
    ll now = initial+(a_diff+b_diff);
    ans = max(ans, now);
  }

  cout << ans << endl;
  return 0;
}