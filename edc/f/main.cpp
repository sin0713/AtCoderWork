#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

void chmax(int& a, int b) {
  if (a < b) a = b;
}

int main() {
  string s, t;
  cin >> s >> t;

  int n = s.size();
  int m = t.size();
  vector<vector<int>> dp(n+1, vector<int>(m+1));

  rep(i, n+1) {
    rep(j, m+1) {
      if (i == 0 || j == 0) {
        continue;
      }

      chmax(dp[i][j], dp[i-1][j]);
      chmax(dp[i][j], dp[i][j-1]);
      if (s[i-1] == t[j-1]) chmax(dp[i][j], dp[i-1][j-1]+1);
    }
  }

  string sna = "";
  while(n > 0 && m > 0) {
    if (dp[n][m] == dp[n-1][m]) {
      n--;
    } else if (dp[n][m] == dp[n][m-1]) {
      m--;
    } else {
      sna += s[n-1];
      n--;
      m--;
    }
  }
  reverse(sna.begin(), sna.end());
  cout << sna << endl;

  return 0;
}