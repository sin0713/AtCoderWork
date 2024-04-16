#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

void chmax(ll& a, ll b) { a = max(a, b); }

int main() {
  int n;
  cin >> n;

  const int T = 100100;
  vector<int> x(T), a(T);
  rep(i, n) {
    int t, X, A;
    cin >> t >> X >> A;
    x[t] = X;
    a[t] = A;
  }

  const ll INF = 1e18;
  vector dp(T+1, vector<ll>(5, -INF));
  dp[0][0] = 0;
  rep(i, T) {
    int ni = i+1;
    rep(j, 5) {
      for (int k = -1; k <= 1; k++) {
        int nj = j+k;
        if (nj < 0 || nj >= 5) continue;

        chmax(dp[ni][nj], dp[i][j]);
      }
    }

    dp[ni][x[ni]] += a[ni];
  }

  ll ans = 0;
  rep(i, 5) {
    ans = max(dp[T][i], ans);
  }
  cout << ans << endl;
  return 0;
}