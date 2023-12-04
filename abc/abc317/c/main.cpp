#include <vector>
#include <algorithm>
#include <iostream>
#include <atcoder/all>
#include <math.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF (1 << 30)

struct Edge
{
  int to;
  int cost;

  Edge(int to=0, int cost=0): to(to), cost(cost) {};
};


int main() {
  int n;
  int m;
  cin >> n >> m;

  vector<vector<Edge>> map(n);
  rep(i, m) {
    int a, b, c;
    cin >> a >> b >> c;

    --a;
    --b;

    map[a].push_back({b, c});
    map[b].push_back({a, c});
  }

  vector<bool> visited(n);
  int ans = 0;
  auto f = [&] (auto f, int v, int total_cost) -> void {
    visited[v] = true;
    ans = max(total_cost, ans);
    for (auto e : map[v]) {
      if (visited[e.to]) continue;
      f(f, e.to, total_cost+e.cost);
    }
    visited[v] = false;
  };

  rep(i, n) f(f, i, 0);

  cout << ans << endl;

  return 0;
}