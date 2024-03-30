#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

bool solve() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> g(n);
  rep(i, m) {
    int v, u;
    cin >> v >> u;
    v--; u--;

    g[v].push_back(u);
    g[u].push_back(v);
  }

  // 頂点数と辺の数
  if (m != n-1) {
    return false;
  }

  int mx_sides = 0;
  vector<int> seen(n);
  auto dfs = [&] (auto dfs, int v) -> void {
    if (seen[v]) return;

    seen[v]++;
    int v_size = g[v].size();
    mx_sides = max(v_size, mx_sides);
    for (auto& v : g[v]) { dfs(dfs, v); }
  };

  dfs(dfs, 0);

  // 辺の数
  if (mx_sides > 2) {
    return false;
  }

  // 連結性
  rep(i, n) {
    if (!seen[i]) return false;
  }

  // ok
  return true;
}

int main() {
  if (solve()) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}