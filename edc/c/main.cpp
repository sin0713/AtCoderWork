#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

void chmax(ll& a, ll b) {
  if (a < b) a = b;
}

int main() {
  int n;
  int m = 3;
  cin >> n;
  vector<vector<int>> v(n, vector<int>(m));
  rep(i, n) {
    rep(j, m) {
      cin >> v[i][j];
    }
  }

  vector<vector<ll>> dp(n, vector<ll>(m));

  // 初期化
  rep(i, m) {
    dp[0][i] = v[0][i];
  }

  rep(i, n-1) {
    rep(j, m) {
      rep(k, m) {
        if (j == k) continue;

        chmax(dp[i+1][k], dp[i][j]+v[i+1][k]);
      }
    }
  }

  ll ans = 0;
  rep(i, m) chmax(ans, dp[n-1][i]);
  
  cout << ans << endl;
  return 0;
}