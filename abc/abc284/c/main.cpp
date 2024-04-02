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

  vector<vector<int>> g(n);
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;

    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<bool> seen(n);
  auto dfs = [&](auto dfs, int v) -> void {
    if (seen[v]) return;

    seen[v] = true;
    for (auto next : g[v]) {
      dfs(dfs, next);
    }
  };

  int ans = 0;
  rep(i, n) {
    if (!seen[i]) {
      ans++;
      dfs(dfs, i);
    }
  }

  cout << ans << endl;
  return 0;
}