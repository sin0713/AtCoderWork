#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(m, vector<int>(n));
  rep(i, m) rep(j, n) {
    int x;
    cin >> x;
    x--;
    a[i][j] = x;
  } 

  vector<vector<int>> cnt(n, vector<int>(n));
  rep(i, m) rep(j, n-1) {
    int x = a[i][j];
    int y = a[i][j+1];
    cnt[x][y]++;
    cnt[y][x]++;
  };

  int ans = 0;
  rep(i, n) rep(j, n) {
    if (i == j) continue;

    if (cnt[i][j] == 0) ans++;
  };

  cout << ans / 2 << endl;
  return 0;
}