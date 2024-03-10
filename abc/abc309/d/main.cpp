#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main()
{
  int n1, n2, m;
  cin >> n1 >> n2 >> m;
  int n = n1+n2;

  vector<vector<int>> g(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  const int INF = 1001001001;
  auto bfs = [&](int start, vector<int>& dist) {
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    
    while(!q.empty()) {
      int v = q.front(); q.pop();

      for (int u : g[v]) {
        if (dist[u] != INF) continue;

        dist[u] = dist[v]+1;
        q.push(u);
      }
    }
  };

  vector<int> d1(n1, INF);
  vector<int> d2(n, INF);
  bfs(0, d1);
  bfs(n-1, d2);

  int ans = 0;
  auto sum = [&] (vector<int> d) {
    int mx = 0;

    rep(i, d.size()) {
      if (d[i] == INF) continue;
      mx = max(mx, d[i]);
    }

    ans += mx;
  };

  sum(d1);
  sum(d2);

  cout << ++ans << endl;
  return 0;
}