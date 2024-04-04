#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

ll c2(ll x) {
  return x * (x-1) / 2;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> g(n); 
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    u--; v--;

    g[v].push_back(u);
    g[u].push_back(v);
  }

  vector<int> color(n, -1);
  vector<int> color_cnt;
  auto dfs = [&] (auto dfs, int v, int col) -> bool {
    if (color[v] != -1) {
      return color[v] == col;
    }

    color[v] = col;
    color_cnt[col]++;
    for (int vv : g[v]) {
      if (!dfs(dfs, vv, col^1)) return false;
    }
    return true;
  };

  ll ans = c2(n) - m;
  rep(i, n) {
    if (color[i] != -1) continue;

    color_cnt = vector<int>(2);
    if (!dfs(dfs, i, 0)) {
      cout << 0 << endl;;
      return 0;
    }

    rep(i, 2) {
      ans -= c2(color_cnt[i]);
    }
  }

  cout << ans << endl;
  return 0;
}
