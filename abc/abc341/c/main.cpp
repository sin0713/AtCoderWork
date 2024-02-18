#include <vector>
#include <algorithm>
#include <iostream>
#include <atcoder/all>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e18
using ll = long long;

int main() {
  int h, w, n;
  cin >> h >> w >> n;

  string t;
  cin >> t;
  vector<string> s(h);
  rep(i, h) {
    cin >> s[i];
  }

  // 全て陸（= '.'）
  int ans = 0;
  rep(i, h) {
    rep(j, w) {
      if (s[i][j] == '#') continue;

      pair<int, int> current = {i, j};
      bool ok = true;
      rep(k, n) {
        if (t[k] == 'L') {
          current.second--;
        } else if (t[k] == 'R') {
          current.second++;
        } else if (t[k] == 'U') {
          current.first--;
        } else if (t[k] == 'D') {
          current.first++;
        }

        if (s[current.first][current.second] == '#') {
          ok = false;
          break;
        }
      }

      if (ok) ans++;
    }
  }

  cout << ans << endl;

  return 0;
}