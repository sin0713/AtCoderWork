#include <vector>
#include <algorithm>
#include <iostream>
#include <atcoder/all>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

void chmin(ll& x, ll y) { x = min(x, y); }

int main() {
  int n;
  cin >> n;
  int w = 0;

  vector<pair<int, int>> data;
  rep(i, n) {
    int x, y, z;
    cin >> x >> y >> z;
    int a = max(0, (y-x+1) / 2);
    w += z;
    data.emplace_back(a, 2*z);
  }

  const ll INF = 1e18;
  vector<vector<ll>> dp(n+1, vector<ll>(w+1, INF));
  dp[0][0] = 0;

  rep(i, n) {
    auto [a, z] = data[i];
    rep(j, w + 1) {
      chmin(dp[i+1][j], dp[i][j]);
      chmin(dp[i+1][min(w, j+z)], dp[i][j]+a);
    }
  }

  cout << dp[n][w] << endl;

  return 0;
}