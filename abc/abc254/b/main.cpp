#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;

  vector<vector<int>> table(n, vector<int>(n));
  rep(i, n) {
    rep(j, i+1) {
      if (j == 0 || j == i) {
        table[i][j] = 1;
        continue;
      }

      table[i][j] = table[i-1][j-1]+table[i-1][j];
    }
  }

  rep(i, n) {
    rep(j, i+1) {
      if (table[i][j] == 0) break;

      cout << table[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}