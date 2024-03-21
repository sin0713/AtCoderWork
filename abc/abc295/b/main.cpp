#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int r, c;
  cin >> r >> c;

  vector<string> b(r);
  rep(i, r) cin >> b[i];

  vector<vector<bool>> blasted(r, vector<bool>(c, false));

  rep(i, r) {
    rep(j, c) {
      if (b[i][j] == '#' || b[i][j] == '.') continue;

      int power = b[i][j] - '0';
      rep(ni, r) {
        rep(nj, c) {
          int dist = abs(ni - i) + abs(nj - j);
          if (dist <= power) blasted[ni][nj] = true;
        }
      }
    }
  }

  rep(i, r) {
    rep(j, c) {
      if (blasted[i][j]) b[i][j] = '.';
    }
  }

  for (string& s : b) cout << s << endl;
  return 0;
}