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
  int n;
  cin >> n;

  int i = 0;
  int j = 0;
  int current = 1;
  vector<vector<int>> ans(n, vector<int>(n, -1));

  auto f = [&](int di, int dj) {
    ans[i][j] = current;
    current++;
    i += di;
    j += dj;
  };

  for (int l = n-1; l > 0; l-=2) {
    rep(i, l) f(0, 1);
    rep(i, l) f(1, 0);
    rep(i, l) f(0, -1);
    rep(i, l-1) f(-1, 0);
    f(0, 1);
  }

  rep(i, n) {
    rep(j, n) {
      if (ans[i][j] == -1) {
        cout << 'T';
      } else {
        cout << ans[i][j];
      }
      cout << ' ';
    }
    cout << endl;
  }

  return 0;
}