#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

void chmin(ll& a, ll b) {
  if (a > b) a = b;
}

int main() {
  int n, W;
  cin >> n >> W;

  vector<ll> w(n);
  vector<ll> v(n);
  rep(i, n) {
    cin >> w[i] >> v[i];
  }

  const int mx = 100100; 
  const ll INF = 1e10;
  // dp[i][j] = i個目までの品物を選べる時,価値jの時の重さ
  vector<vector<ll>> dp(n+1, vector<ll>(mx, INF));
  dp[0][0] = 0;
  for (int i = 1; i < n+1; i++) {
    rep(j, mx) {
      if (j-v[i-1] >= 0 ) {
        chmin(dp[i][j], dp[i-1][j-v[i-1]]+w[i-1]);
      };
      chmin(dp[i][j], dp[i-1][j]);
    }
  }

  ll ans = 0;
  rep(i, mx) {
    if (dp[n][i] <= W) {
      ans = max(ans, (ll)i);
    }
  }

  cout << ans << endl;
  return 0;
}