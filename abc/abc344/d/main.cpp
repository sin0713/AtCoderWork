#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

void chmin(int& a, int b) {
  if (a > b) a = b;
}

int main() {
  string t;
  cin >> t;
  int m = t.size();

  int n;
  cin >> n;
  vector<vector<string>> A;
  rep(i, n) {
    int a;
    cin >> a;
    vector<string> s(a);
    rep(i, a) cin >> s[i];
    A.push_back(s);
  }

 
  const int INF = 100100;
  vector<vector<int>> dp(n+1, vector<int>(m+1, INF));
  dp[0][0] = 0;

  rep(i, n) {
    rep(j, m+1) {
      chmin(dp[i+1][j], dp[i][j]);

      rep(ai, A[i].size()) {
        string s = A[i][ai]; // 追加しようとしている文字
        int l = s.size();
        if (j+l > m) continue;

        bool ok = true;
        rep(si, l) {
          char tc = t[j+si];
          char sc = s[si];
          if (t[j+si] != s[si]) ok = false;
        }
        if (ok) chmin(dp[i+1][j+l], dp[i][j]+1);
      }

    }
  }

  if (dp[n][m] == INF) cout << -1 << endl;
  else cout << dp[n][m] << endl;
  return 0;
}