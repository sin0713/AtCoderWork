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
    int a, b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  vector<bool> seen(n);
  auto dfs = [&] (auto dfs, int v, int& count) -> void {
    if (seen[v]) return;

    seen[v] = true;
    count++;
    for (auto& next : g[v]) {
      dfs(dfs, next, count);
    }
  };

  vector<int> v_count(n);
  rep(i, n) {
    dfs(dfs, i, v_count[i]);
  }

  int ans = m;
  rep(i, n) {
    if (v_count[i]) {
      ans -= (v_count[i] - 1);
    }
  }
  cout << ans << endl;
  return 0;
}