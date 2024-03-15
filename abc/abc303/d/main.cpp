#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

void chmin(ll& a, ll b) { a = min(a, b); }

int main()
{
  ll x, y, z;
  cin >> x >> y >> z;

  string s;
  cin >> s;

  const ll INF = 1e18;
  int n = s.size();
  vector<vector<ll>> dp(n+1, vector<ll>(2, INF));
  dp[0][0] = 0;
  rep(i, n) {
    if (s[i] == 'A') {
      // capslock and a
      chmin(dp[i+1][1], dp[i][0] + z + x); 
      // shift
      chmin(dp[i+1][0], dp[i][0] + y);

      // a
      chmin(dp[i+1][1], dp[i][1] + x);
      // caps + shift
      chmin(dp[i+1][0], dp[i][1] + z + y);
    } else {
      // a
      chmin(dp[i+1][0], dp[i][0] + x);
      // caps shift
      chmin(dp[i+1][1], dp[i][0] + y + z);

      // shift
      chmin(dp[i+1][1], dp[i][1] + y);
      // capslock and a
      chmin(dp[i+1][0], dp[i][1] + x + z);
    }
  }

  ll ans = min(dp[n][0], dp[n][1]);
  cout << ans << endl;
  return 0;
}