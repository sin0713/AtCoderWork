#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

ll dp[105][105][100];
void chmax(ll&a, ll b) { a = max(a, b); };

int main() {
  int n, k, d;
  cin >> n >> k >> d;

  vector<int> a(n);
  rep(i, n) cin >> a[i];

  rep(i, n+1)rep(j, k+1)rep(r, d) dp[i][j][r] = -1;
  dp[0][0][0] = 0;

  rep(i, n) {
    int ni = i+1;
    rep(j, k+1) rep(r, d) {
      ll now = dp[i][j][r];
      if (now == -1) continue;

      { // use
        int nj = j+1;
        int nr = (r+a[i])%d;
        chmax(dp[ni][nj][nr], now+a[i]);
      }
      { // not use
        int nj = j, nr = r;
        chmax(dp[ni][nj][nr], now);
      }
    }
  }

  cout << dp[n][k][0] << endl;
  return 0;
}