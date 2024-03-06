#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

void chmin(ll& a, ll b) {
  if (a > b) a = b;
}

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> h(n);
  rep(i, n) cin >> h[i];

  const ll INF = 1e18;
  vector<ll> dp(n, INF); 
  dp[0] = 0;
  rep(i, n) {
    for (int j = 1; j <= k; j++) {
      if (i + j >= n) continue;

      chmin(dp[i+j], dp[i]+abs(h[i+j] - h[i]));
    }
  }

  cout << dp[n-1] << endl;
  return 0;
}