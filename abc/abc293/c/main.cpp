#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int h, w;
  cin >> h >> w;

  vector<vector<int>> a(h, vector<int>(w));
  rep(i, h) rep(j, w) cin >> a[i][j];

  int ans = 0;
  auto dfs = [&](auto dfs, int i, int j, unordered_map<int, int> mp) -> void {
    cout << "i: " << i << " j: " << j << endl;
    if (i == h-1 && j == w-1) {
      bool ok = true;
      for (auto [k, v] : mp) {
        if (v > 1) ok = false;
      }
      if (ok) {
        ans++;
      }
      return;
    }

    if (i < 0 || i >= h || j < 0 || j >= w) {
      return;
    }

    mp[a[i][j]]++;
    dfs(dfs, i+1, j, mp);
    dfs(dfs, i, j+1, mp);
  };

  unordered_map<int, int> mp;
  dfs(dfs, 0, 0, mp);

  cout << ans << endl;
  return 0;
}