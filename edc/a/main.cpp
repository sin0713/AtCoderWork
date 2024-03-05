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

int main() {
  int n;
  cin >> n;

  vector<int> h(n);
  rep(i, n) cin >> h[i];

  // i: 足場iまで決める
  // dp[i]: 足場iにたどり着くまでの最小コスト
  const ll INF = 1e9;
  vector<ll> dp(n, INF);
  dp[0] = 0;

  rep(i, n-1) {
    dp[i+1] = min(dp[i+1], dp[i] + abs(h[i+1]-h[i]));
    if (i+2 < n) {
      dp[i+2] = min(dp[i+2], dp[i] + abs(h[i+2]-h[i]));
    }
  }

  cout << dp[n-1] << endl;
  return 0;
}