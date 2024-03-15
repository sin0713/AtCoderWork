#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m; ll d;
  cin >> n >> m >> d;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  vector<ll> b(m);
  rep(i, m) cin >> b[i];

  sort(b.begin(), b.end());
  ll ans = -1;
  rep(i, n) {
    ll l = a[i]-d;  
    ll r = a[i]+d;  
    int x = upper_bound(b.begin(), b.end(), r) - b.begin();
    if (x > 0) {
      ll value = b[x-1];
      if (value >= l) ans = max(ans, value + a[i]);
    }
  }

  cout << ans << endl;
  return 0;
}