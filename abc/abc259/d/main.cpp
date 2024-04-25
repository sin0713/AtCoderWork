#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

struct V {
  ll x, y;
  V(){};
  V(ll x, ll y): x(x), y(y) {};
};

int main() {
  int n;
  cin >> n;
  V start, goal;
  cin >> start.x >> start.y >> goal.x >> goal.y;

  vector<V> cs(n);
  vector<int> rs(n);
  rep(i, n) {
    cin >> cs[i].x >> cs[i].y >> rs[i];
  }

  auto pow2 = [](ll x) { return x*x; };

  auto dist = [&] (V a, V b) -> ll {
    ll dx = a.x - b.x;
    ll dy = a.y - b.y;
    return pow2(dx) + pow2(dy);
  };

  // start, endの頂点をもとめる
  int sv = 0, gv = 0;
  rep(i, n) {
    if (dist(start, cs[i]) == pow2(rs[i])) sv = i;
    if (dist(goal, cs[i]) == pow2(rs[i])) gv = i;
  }

  // グラフを作成
  vector<vector<int>> g(n);
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      // 中心間の距離
      ll d = dist(cs[i], cs[j]);

      int r1 = rs[i], r2 = rs[j];
      if (r1 > r2) swap(r1, r2);

      if (d > pow2(r1+r2)) continue;
      if (d < pow2(r2-r1)) continue;

      g[i].push_back(j);
      g[j].push_back(i);
    }
  }

  // DFS
  vector<bool> seen(n, false);
  auto dfs = [&](auto dfs, int current) {
    if (seen[current]) return;

    seen[current] = true;
    for (int v : g[current]) {
      dfs(dfs, v);
    }
  };
  dfs(dfs, sv);

  if (seen[gv]) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}