#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e18
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> x(m);
  rep(i, m) cin >> x[i];

  vector<ll> d(n+1);
  auto add = [&](ll l, ll r, ll value) {
    d[l] += value;
    d[r] -= value;
  };

  rep(i, m-1) {
    ll s = x[i]; 
    ll t = x[i+1]; 
    if (s > t) swap(s, t);

    ll a = t - s;
    ll b = n - a;

    add(0, s, a);
    add(s, t, b);
    add(t, n, a);
  }

  // 差分の列から復元
  rep(i, n) d[i+1] += d[i];

  ll ans = 1e18;
  rep(i, n) {
    ans = min(ans, d[i]);
  }
  cout << ans << endl;
}