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
  int h, w, k;
  cin >> h >> w >> k;

  vector<string> s(h);
  rep(i, h) cin >> s[i];

  const int INF = 1e6;
  auto solve = [&] (string s) -> int {
    int xs = 0;
    int dots = 0;
    int res = INF;

    int n = s.size();
    int ln = 0;
    rep(i, n) {
      if (s[i] == 'x') xs++;
      if (s[i] == '.') dots++;
      ln++;

      if (ln > k) {
        if (s[i - k] == 'x') xs--; 
        if (s[i - k] == '.') dots--; 
        ln--;
      }

      if (ln == k) {
        if (xs == 0) res = min(res, dots);
      }
    }

    return res;
  };


  int ans = INF;
  rep(i, 2) {
    rep(j, h) {
      ans = min(ans, solve(s[j]));
    }

    vector<string> t(w, string(h, '.')); 
    rep(i, h) rep(j, w) t[j][i] = s[i][j];
    s = t;
    swap(h, w);
  }

  if (ans == INF) cout << -1 << endl;
  else cout << ans << endl;
  return 0;
}