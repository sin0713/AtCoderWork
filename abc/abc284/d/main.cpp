#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

void solve() {
  ll n;
  cin >> n;

  for (ll x = 2; ; x++) {
    if (n % x) continue;

    n /= x;
    if (n % x == 0) {
      printf("%lld %lld\n", x, n / x);
      return;
    }

    ll p = round(sqrt(n));
    printf("%lld %lld\n", p, x);
    return;
  }
}

int main() {
  int t;
  cin >> t;

  rep(i, t) solve();
  return 0;
}