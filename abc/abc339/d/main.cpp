#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i, n) cin >> s[i];

  vector<pair<int, int>> directions 
  {
    {0, -1}, // left
    {0, 1},  // right
    {-1, 0}, // up
    {1, 0}   // down
  };

  auto to_i = [&](vector<pair<int, int>>& ps) {
    int res = 0;
    res = res * n + ps[0].first;
    res = res * n + ps[0].second;
    res = res * n + ps[1].first;
    res = res * n + ps[1].second;
    return res;
  };

  auto to_ps = [&] (int id) {
    vector<pair<int, int>> ps(2);
    rep(i, 2) {
      int second = id % n; id /= n;
      int first = id % n; id /= n;
      ps[i] = {first, second};
    }
    return ps;
  };

  const int INF = 1e9;
  int m = n*n*n*n;
  vector<int> dist(m, INF);
  queue<int> q;
  vector<pair<int, int>> current_pos;
  rep(i, n) {
    rep(j, n) {
      if (s[i][j] == 'P') current_pos.emplace_back(i, j);
    }
  }

  int initial_id = to_i(current_pos);
  dist[initial_id] = 0;
  q.push(initial_id);
  int ans = INF;
  while(!q.empty()) {
    int id = q.front(); q.pop();
    vector<pair<int, int>> origin_pos = to_ps(id);

    for (pair<int, int>& direction : directions) {
      vector<pair<int, int>> pos_list;
      for (pair<int, int>& pos : origin_pos) {
        int move_i = pos.first + direction.first;
        int move_j = pos.second + direction.second;
        if (move_i < 0 || move_j < 0 || move_i >= n || move_j >= n || s[move_i][move_j] == '#') {
          move_i = pos.first;
          move_j = pos.second;
        }
        pos_list.emplace_back(move_i, move_j);
      }
      int nid = to_i(pos_list);
      if (dist[nid] != INF) continue;

      dist[nid] = dist[id] + 1;
      q.push(nid);
      if (pos_list[0] == pos_list[1]) ans = min(ans, dist[nid]);
    }
  }

  if (ans == INF) cout << -1 << endl; else cout << ans << endl;

  return 0;
}