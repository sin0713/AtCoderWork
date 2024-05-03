#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

const vector<int> dx = {0, 0, -1, 1};
const vector<int> dy = {-1, 1, 0, 0};


int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, h) cin >> s[i];

  vector x(h, vector<bool>(w));
  rep(i, h) rep(j, w) if (s[i][j] == '#') {
    x[i][j] = true;
    rep(di, 4) {
      int ni = i+dy[di], nj = j+dx[di];
      if (ni < 0 || ni >= h || nj < 0 || nj >= w) {
        continue;
      }

      x[ni][nj] = true;
    }
  }

  set<P> visited;
  vector last(h, vector<int>(w));
  int time = 0;
  auto dfs = [&](auto dfs, P pos, int& cnt) { 
    if (visited.count(pos)) return;

    cnt++;
    visited.insert(pos);
    auto [pi, pj] = pos;
    rep(di, 4) {
      int ni = pi+dy[di], nj = pj+dx[di];
      if (ni < 0 || ni >= h || nj < 0 || nj >= w) {
        continue;
      }

      if (x[ni][nj]) {
        if (last[ni][nj] != time) {
          last[ni][nj] = time;
          cnt++;
        }
        continue;
      }

      dfs(dfs, pair(ni, nj), cnt);
    }
  };

  int ans = 1;
  rep(i, h) {
    rep(j, w) {
      if (x[i][j]) continue;

      auto current = pair(i, j);
      if (visited.count(current)) continue;

      int cnt = 0;
      time++;
      dfs(dfs, current, cnt);
      ans = max(ans, cnt);
    }
  }

  cout << ans << endl;
}
