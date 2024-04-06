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
  vector<int> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];

  rep(i, n) {
    int ans = 0;
    ll now = -1;
    rep(j, n) {
      ll dist_x = abs(x[i] - x[j]);
      ll dist_y = abs(y[i] - y[j]);
      ll sum  = dist_x * dist_x + dist_y * dist_y;
      if (now < sum) {
        now = sum;
        ans = j;
      }
    }
    cout << ans+1 << '\n';
  }
  return 0;
}