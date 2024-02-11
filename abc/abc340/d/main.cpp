#include <vector>
#include <algorithm>
#include <iostream>
#include <atcoder/all>
#include <math.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

struct Edge {
  int to, cost;
  Edge() {};
  Edge(int to, int cost): to(to), cost(cost) {};
};

int main()
{
  int n;
  cin >> n;

  vector<vector<Edge>> graph(n);
  rep(i, n-1) {
    int a, b, x;
    cin >> a >> b >> x;
    x--;
    graph[i].emplace_back(i+1, a);
    graph[i].emplace_back(x, b);
  }

  using ll = long long;
  using P = pair<ll, int>; // first: cost, second: 頂点
  const ll INF = 1e18;
  vector<ll> dist(n, INF); // ノードの最小コスト保持
  priority_queue<P, vector<P>, greater<P>> q; // 未確定ノードの集合

  // 初期化
  dist[0] = 0; // 確定
  q.emplace(0, 0);

  while(!q.empty()) {
    auto [c, v] = q.top(); q.pop();
    if (dist[v] != c) continue;

    // ノードvから辿れるノードを探索
    for (Edge to_edge : graph[v]) {
      ll update_value = c + to_edge.cost;
      if (update_value >= dist[to_edge.to]) continue;

      dist[to_edge.to] = update_value;
      q.emplace(update_value, to_edge.to);
    }
  }

  cout << dist[n-1] << endl;

  return 0;
}