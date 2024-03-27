#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int t;
  cin >> t;

  rep(i, t) {
    int n, d, k;
    cin >> n >> d >> k;
    k--;

    ll g = gcd(n, d);
    ll dd = d / g; 
    ll nn = n / g;
    ll m = n / g;

    ll position = ((ll)(k * dd) % nn) * g;  
    ll count = k / m;
    ll ans = position + count;
    cout << ans << endl;
  }
  return 0;
}