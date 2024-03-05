#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;
using mint = modint998244353;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e18
using ll = long long;

int main() {
  string s;
  cin >> s;

  int n = s.size();

  // i: i文字目まで決めたとき
  // j: そのときの合計値()
  // dp[i][j]: i文字目まで
  vector<vector<mint>> dp(n+1, vector<mint>(n+1));
  dp[0][0] = 1;

  rep(i, n) {
    rep(j, n) {
      if (s[i] != ')') dp[i+1][j+1] += dp[i][j];
      if (s[i] != '(' && j != 0) dp[i+1][j-1] += dp[i][j];
    }
  }

  cout << dp[n][0].val() << endl;
  return 0;
}