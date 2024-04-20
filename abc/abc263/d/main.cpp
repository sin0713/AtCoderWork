#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n, L, R;
  cin >> n >> L >> R;

  vector<int> a(n);
  rep(i, n) cin >> a[i];

  ll ans = n*R; 
  ll suma = 0, sumb = 0, maxb = 0;
  rep(r, n) {
    suma += a[r];
    sumb += a[r] - L;
    maxb = max(sumb, maxb);

    ll now = suma - maxb + ll(n-r-1)*R;
    ans = min(ans, now);
  }

  cout << ans << endl;
  return 0;
}