#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<ll, ll>;

void chmax(ll& a, ll b) {
  if (a < b) a = b;
}

int main() {
  int n, w;
  cin >> n >> w;

  vector<P> d(n);
  rep(i, n) {
    ll w, v;
    cin >> w >> v;

    d[i] = {w, v};
  }

  vector<vector<ll>> dp(n+1, vector<ll>(w+1));
  rep(i, n) {
    rep(j, w+1) {
      if (j + d[i].first <= w) {
        // i番目の品物を選ぶ
        chmax(dp[i+1][j+d[i].first], dp[i][j]+d[i].second);
      }

      // i番目の品物を選ばない
      chmax(dp[i+1][j], dp[i][j]);
    }
  }

  cout << dp[n][w] << endl;
  return 0;
}