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
  int h, w;
  cin >> h >> w;

  vector<string> s(h);
  rep(i, h) {
    cin >> s[i];
  }

  vector<vector<int>> a(h, vector<int>(w));
  rep(i, h) rep(j, w) a[i][j] = s[i][j] - 'a';

  const int m = 26;
  vector cnt_row(h, vector<int>(m));
  vector cnt_col(w, vector<int>(m));
  rep(i, h) {
    rep(j, w) {
      cnt_row[i][a[i][j]]++;
      cnt_col[j][a[i][j]]++;
    }
  }

  vector<bool> deleted_row(h);
  vector<bool> deleted_col(w);

  auto to_delete = [&] (vector<int>& x) -> bool {
    int tot = 0; 
    int k = 0;
    rep(i, m) {
      if (x[i] <= 0) continue;

      tot += x[i];
      k++;
    }

    return tot >= 2 && k == 1;
  }; 

  auto remove = [&] (int i, int j)  {
    if (deleted_col[j] || deleted_row[i]) return;

    cnt_row[i][a[i][j]]--;
    cnt_col[j][a[i][j]]--;
  };

  bool upd = true;
  while(upd) {
    upd = false;

    vector<int> del_row, del_col;
    rep(i, h) {
      if (to_delete(cnt_row[i])) del_row.push_back(i);
    }
    rep(i, w) {
      if (to_delete(cnt_col[i])) del_col.push_back(i);
    }

    for (int i : del_row) {
      rep(j, w) { remove(i, j); }
      deleted_row[i] = true;
      upd = true;
    }

    for (int j : del_col) {
      rep(i, h) { remove(i, j); }
      deleted_col[j] = true;
      upd = true;
    }
  }

  int ans = 0;
  rep(i, h) {
    rep(j, w) {
      if (deleted_col[j] || deleted_row[i]) continue;
      
      ans++;
    }
  }

  cout << ans << endl;

  return 0;
}