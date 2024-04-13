#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll s = 0;
  ll t = 0;
  rep(i, m) {
    s += a[i] * (i+1);
    t += a[i];
  } 

  ll ans = s;
  rep(i, n-m) {
    s = s - t + (m * a[i+m]);
    ans = max(ans, s);

    t = t - a[i] + a[i+m];
  }

  cout << ans << endl;
  return 0;
}