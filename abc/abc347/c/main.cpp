#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n, a, b;
  cin >> n >> a >> b;

  ll m = a+b;
  vector<ll> d(n);
  rep(i, n) { 
    ll x;
    cin >> x;

    x %= m;
    d[i] = x;
  }

  sort(d.begin(), d.end());
  ll min = d[0];
  ll mx = d[n-1];
  ll range = mx - min;
  range++;

  if (range <= a) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}