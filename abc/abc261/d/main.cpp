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
  vector<ll> x(n);
  rep(i, n) cin >> x[i];

  unordered_map<int, ll> bonus;
  rep(i, m) {
    int c;
    ll y;
    cin >> c >> y;
    bonus[c] = y;
  }

  const ll INF = 1e18;
  vector dp(n+1, vector<ll>(n+1, -INF));
  dp[0][0] = 0;
  
  rep(i, n) {
    rep(j, n) {
      // omote
      chmax(dp[i+1][j+1], dp[i][j]+x[i]);

      // ura
      chmax(dp[i+1][0], dp[i][j]);

      // bonus
      if (bonus.count(j+1)) {
        dp[i+1][j+1] += bonus[j+1];
      }
    }
  }

  ll ans = 0;
  rep(i, n+1) {
    ans = max(ans, dp[n][i]);
  }

  cout << ans << endl;
  return 0;
}
