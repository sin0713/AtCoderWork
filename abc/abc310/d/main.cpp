#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, t, m;
  cin >> n >> t >> m;

  vector<vector<bool>> bad(n, vector<bool>(n));
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    bad[a][b] = true;
    bad[b][a] = true;
  }

  int ans = 0;
  vector<vector<int>> teams;
  auto f = [&] (auto f, int i) -> void {
    if (i == n) {
      if (teams.size() == t) ans++;
      return;
    }

    rep(j, teams.size()) {
      bool ok = true;
      for (int player : teams[j]) {
        if (bad[i][player]) ok = false;
      }

      if (!ok) continue;

      teams[j].push_back(i);
      f(f, i+1);
      teams[j].pop_back();
    }

    vector<int> newteam(1, i);
    teams.push_back(newteam);
    f(f, i+1);
    teams.pop_back();
  };

  f(f, 0);

  cout << ans << endl;
  return 0;
}