#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, x;
  cin >> n >> x;

  vector<int> moneys;
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    rep(i, b) {
      moneys.push_back(a);
    }
  }

  n = moneys.size();
  vector<vector<int>> dp(n+1, vector<int>(x+1));
  dp[0][0] = 1;
  rep(i, n) {
    rep(j, x+1) {
      if (dp[i][j]) {
        dp[i+1][j] = 1;
        if (j+moneys[i] <= x) dp[i+1][j+moneys[i]] = 1;
      }
    }
  }

  if (dp[n][x]) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}