#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

void chmax(ll& a, ll b) { a = max(a, b); }

int main() {
  int n, m;
  cin >> n >> m;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  const ll INF = 1e18;
  vector<vector<ll>> dp(n+1, vector<ll>(m+1, -INF));
  dp[0][0] = 0;

  rep(i, n) {
    rep(j, m+1) {
      chmax(dp[i+1][j], dp[i][j]);

      if (j+1 <= m) chmax(dp[i+1][j+1], dp[i][j]+a[i]*(j+1));
    }
  }

  cout << dp[n][m] << endl;
  return 0;
}