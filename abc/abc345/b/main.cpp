#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  ll x;
  cin >> x;

  ll ans = 0;
  if (x < 0) {
    ans = x / 10;
    cout << ans << endl;
    return 0;
  }

  if (x % 10 != 0) {
    ans = (ll)(x / 10) + 1;
    cout << ans << endl;
    return 0;
  }

  ans = x / 10;
  cout << ans << endl;
  return 0;
}