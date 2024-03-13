#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

void chmax(ll& a, ll b) { a = max(a, b); } 

int main()
{
  int n;
  cin >> n;
  vector<int> x(n);
  vector<int> y(n);
  rep(i, n) {
    cin >> x[i] >> y[i];
  }

  const ll INF = 1e18;
  vector<vector<ll>> dp(n+1, vector<ll>(2, -INF));
  dp[0][0] = 0;

  rep(i, n) {
    rep(j, 2) {
      // 食べない
      chmax(dp[i+1][j], dp[i][j]);

      if (x[i] == 0) {
        // 解毒
        if (j == 1) {
          chmax(dp[i+1][j-1], dp[i][j]+y[i]);
        } else {
          chmax(dp[i+1][j], dp[i][j]+y[i]);
        }
      } else {
        if (j == 0) chmax(dp[i+1][j+1], dp[i][j]+y[i]); 
      }
    }
  }

  ll ans = max(dp[n][0], dp[n][1]);
  cout << ans << endl;
  return 0;
}