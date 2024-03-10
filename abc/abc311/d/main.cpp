#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

const vector<int> dy = {-1, 0, 1, 0};
const vector<int> dx = {0, 1, 0, -1};

int main() {
  int n, m;
  cin >> n >> m;

  vector<string> s(n);
  rep(i, n) cin >> s[i];

  vector<vector<bool>> visited(n, vector<bool>(m)); 
  vector<vector<bool>> passed(n, vector<bool>(m)); 
  queue<P> q;
  q.emplace(1, 1);
  visited[1][1] = true;
  passed[1][1] = true;

  while(!q.empty()) {
    auto [i, j] = q.front(); q.pop();

    rep(v, 4) {
      int ci = i;
      int cj = j;
      while(s[ci][cj] == '.') {
        passed[ci][cj] = true;
        ci += dy[v]; cj += dx[v];
      }

      ci -= dy[v]; cj -= dx[v];
      if (visited[ci][cj]) { continue; }

      visited[ci][cj] = true;
      passed[ci][cj] = true;
      q.emplace(ci, cj);
    }
  }

  int ans = 0;
  rep(i, n) {
    rep(j, m) {
      if (passed[i][j]) ans++;
    }
  }

  cout << ans << endl;
  return 0;
}