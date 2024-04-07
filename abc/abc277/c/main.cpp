#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;

  map<int, vector<int>> to;
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }

  set<int> can;
  auto dfs = [&](auto dfs, int v) -> void {
    if (can.count(v)) return;

    can.insert(v);
    if (to.count(v)) {
      for (auto u : to[v]) {
        dfs(dfs, u);
      }
    }
  };

  dfs(dfs, 0);

  auto itr = can.end();
  itr--;
  int ans = *itr + 1;
  cout << ans << endl;
  return 0;
}