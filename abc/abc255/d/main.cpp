#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, q;
  cin >> n >> q;

  vector<int> a(n);
  rep(i, n) cin >> a[i];
  sort(a.begin(), a.end());
  vector<ll> s(n+1); 
  rep(i, n) s[i+1] = s[i] + a[i];

  rep(i, q) {
    int x;
    cin >> x;

    int k = lower_bound(a.begin(), a.end(), x) - a.begin();
    ll ans = (ll)k * x - s[k];
    ans += (s[n]-s[k]) - (ll)(n-k)*x;
    cout << ans << '\n';
  }
  return 0;
}