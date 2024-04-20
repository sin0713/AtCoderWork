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
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  auto hasLink = [&](int u, int v) -> bool {
    for (auto m : g[u]) {
      if (m == v) return true;
    }
    return false;
  };

  int ans = 0;
  rep(i, n) {
    for (int j = i+1; j < n; j++) {
      for (int k = j+1; k < n; k++) { 
        if (hasLink(i, j) && hasLink(j, k) && hasLink(k, i)) {
          ans++;
        }
      }
    }
  }

  cout << ans << endl;
  return 0;
}