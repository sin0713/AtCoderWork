#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

void set_memo(vector<vector<int>>& x, vector<int> memo) {
  int index = 0;
  rep(i, 2) {
    rep(j, 2) {
      x[i][j] = memo[index];
      index++;
    }
  }
}

int main() {
  int n = 3;
  vector<int> h(n), w(n);
  rep(i, n) cin >> h[i];
  rep(i, n) cin >> w[i];

  vector<int> memo;
  int ans = 0;
  auto dfs = [&](auto dfs) {
    if (memo.size() == 4) {
      vector a(n, vector<int>(n));
      set_memo(a, memo);

      rep(i, 2) { 
        a[i][2] = h[i]-(a[i][0]+a[i][1]);
        if (a[i][2] <= 0) return;
      }
      rep(i, n) { 
        a[2][i] = w[i]-(a[0][i]+a[1][i]);
        if (a[2][i] <= 0) return;
      }

      int h3_sum = 0;
      rep(i, n) h3_sum += a[2][i];
      if (h[2] != h3_sum) return;

      ans++;
      return;
    } 
    
    for (int i = 1; i <= 30; i++) {
      memo.push_back(i);
      dfs(dfs);
      memo.pop_back();
    }
  };

  dfs(dfs);
  cout << ans << endl;
  return 0;
}