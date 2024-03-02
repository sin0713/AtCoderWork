#include <vector>
#include <algorithm>
#include <iostream>
#include <atcoder/all>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9
using ll = long long;

int main() {
  int n;
  cin >> n;

  vector<vector<int>> g(n);
  rep(i, n-1) {
    int a, b;
    cin >> a >> b;
    a--; b--;

    g[a].push_back(b);
    g[b].push_back(a);
  }

  auto f = [&] (auto f, int v, int p = -1) -> int {
    int res = 1;

    for (int node : g[v]) {
      if (node == p) continue;

      res += f(f, node, v);
    }
    return res;
  };

  int ans = INF;
  for (int node : g[0]) {
    ans = min(ans, n-f(f, node, 0));
  }
  cout << ans << endl;
  return 0;
}