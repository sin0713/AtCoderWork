#include <vector>
#include <algorithm>
#include <iostream>
#include <atcoder/all>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e18
using ll = long long;

struct Edge {
  int to, x, y;

  Edge(int to , int x, int y): to(to), x(x), y(y) {};
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<Edge>> g(n);
  rep(i, m) {
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    a--;
    b--;
    
    g[a].emplace_back(b, x, y);
    g[b].emplace_back(a, -x, -y);
  }

  vector<pair<ll, ll>> coordinates(n, {INF, INF});
  coordinates[0] = {0, 0};

  queue<int> q;
  q.push(0);

  while(!q.empty()) {
    int v = q.front(); q.pop();

    for (auto &edge : g[v]) {
      if (coordinates[v].first == INF) continue;
      if (coordinates[edge.to].first != INF) continue;

      ll x = coordinates[v].first + edge.x;
      ll y = coordinates[v].second + edge.y;
      coordinates[edge.to] = {x, y};
      q.push(edge.to);
    }
  }

  rep(i, n) {
    if (coordinates[i].first == INF) {
      cout << "undecidable" << '\n';
      continue;
    }

    cout << coordinates[i].first << " " << coordinates[i].second << '\n';
  }

  return 0;
}