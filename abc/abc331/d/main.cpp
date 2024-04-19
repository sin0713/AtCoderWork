#include <bits/stdc++.h>

using namespace std;
using ll = long long; 

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF (1 << 30)

int main() {
  int n, q;
  cin >> n >> q;

  vector<string> a(n);
  rep(i, n) cin >> a[i];

  // 二次元累積和
  vector<vector<int>> s(n+1, vector<int>(n+1));
  rep(i, n) rep(j, n) s[i+1][j+1] = (a[i][j] == 'B');
  rep(i, n) rep(j, n) s[i+1][j+1] += s[i+1][j];
  rep(i, n) rep(j, n) s[i+1][j+1] += s[i][j+1];

  auto f = [&] (int c, int d) {
    ll res = s[c%n][d%n];
    res += s[n][n]*ll(c/n)*(d/n);
    res += s[n][d%n]*ll(c/n);
    res += s[c%n][n]*ll(d/n);
    return res;
  };

  rep(i, q) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    c++; d++;

    ll ans = f(c, d) - f(a, d) - f(c, b) + f(a, b);
    cout << ans << '\n';
  }
  return 0;
}