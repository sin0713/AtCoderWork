#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

vector<int> dx = {0, 0, -1, 1};
vector<int> dy = {-1, 1, 0, 0};

struct Med {
  int r, c, e;

  Med(){};
  Med(int r, int c, int e): r(r), c(c), e(e) {};
};

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> a(h, string(w, '.'));
  P start;
  P goal;
  rep(i, h) {
    rep(j, w) {
      char c;
      cin >> c;
      if (c == 'S') {
        start = pair(i, j);
      } else if (c == 'T') {
        goal = pair(i, j);
      }
      a[i][j] = c;
    }
  }

  int n;
  cin >> n;
  vector<Med> meds(n);
  rep(i, n) {
    int a, b, e;
    cin >> a >> b >> e;
    a--;
    b--;

    meds[i] = Med(a, b, e);
  }
  meds.emplace_back(start.first, start.second, 0);
  meds.emplace_back(goal.first, goal.second, 0);
  n+=2;
  int si = n-2;
  int gi = n-1;

  auto out_grid = [&](int i, int j) -> bool {
    return i < 0 || j < 0 || i >= h || j >= w;
  };

  const ll INF = 1e9;
  vector<vector<int>> to(n);
  rep(i, n) {
    vector<vector<int>> dist(h, vector<int>(w, INF));
    auto [r, c, e] = meds[i];
    dist[r][c] = 0;
    queue<P> q;
    q.emplace(r, c);

    // BFS
    while(!q.empty()) {
      auto [i, j] = q.front(); q.pop();

      rep(dr, 4) {
        int ni = i+dy[dr];
        int nj = j+dx[dr];

        if (out_grid(ni, nj)) continue;
        if (a[ni][nj] == '#') continue;
        if (dist[ni][nj] != INF) continue;

        dist[ni][nj] = dist[i][j]+1;
        q.emplace(ni, nj);
      }
    }

    // 始点の薬からたどり着ける薬の辺をはる
    rep(ni, n) if (i != ni) {
      auto [rr, cc, ee] = meds[ni];
      if (dist[rr][cc] <= e) to[i].push_back(ni);
    }
  }

  vector<int> can_reach(n, INF);
  can_reach[si] = 0;
  queue<int> q2;
  q2.push(si);
  while(!q2.empty()) {
    int v = q2.front(); q2.pop();

    for (auto u : to[v]) {
      if (can_reach[u] != INF) continue;
      can_reach[u] = can_reach[v]+1;
      q2.push(u);
    }
  }

  if (can_reach[gi] != INF) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}