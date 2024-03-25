#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;
using mint = modint998244353;

int main() {
  int n;
  cin >> n;

  const int m = 2;
  vector<vector<int>> ab(n, vector<int>(m));
  rep(i, n) rep(j, m) cin >> ab[i][j];

  vector<vector<mint>> dp(n, vector<mint>(m));
  dp[0][0] = 1;
  dp[0][1] = 1;
  for (int i = 1; i < n; i++) {
    rep(j, m) { // 
      rep(k, m) {  
        if (ab[i][j] != ab[i-1][k]) {
          dp[i][j] += dp[i-1][k];
        }
      }
    }
  }

  mint ans = dp[n-1][0] + dp[n-1][1];
  cout << ans.val() << endl;
  return 0;
}