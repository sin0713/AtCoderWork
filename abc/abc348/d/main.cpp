#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

vector<int> dx = {0, 0, -1, 1};
vector<int> dy = {-1, 1, 0, 0};

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
  vector<int> r(n);
  vector<int> c(n);
  vector<int> e(n);
  rep(i, n) {
    int a, b, d;
    cin >> a >> b >> d;
    a--;
    b--;
    r[i] = a;
    c[i] = b;
    e[i] = d;
  }
  map<P, int> mp;
  rep(i, n) { mp[pair(r[i], c[i])] = e[i]; }

  auto out_grid = [&](int i, int j) -> bool {
    return i < 0 || j < 0 || i >= h || j >= w;
  };

  int energy = 0;
  bool isOk = false;
  vector<vector<bool>> seen(h, vector<bool>(w));
  auto dfs = [&](auto dfs, int i, int j) -> void {
    if (out_grid(i, j))
      return;
    if (seen[i][j]) return;
    if (a[i][j] == '#')
      return;
    if (a[i][j] == 'T') {
      isOk = true;
      return;
    }

    P pos = pair(i, j);
    if (mp.count(pos) && mp[pos] > energy) {
      energy = mp[pos];
      mp.erase(pos);
    }

    if (energy <= 0) {
      return;
    }

    seen[i][j] = true;
    rep(k, 4) { 
      dfs(dfs, i + dy[k], j + dx[k]); 
    }
    seen[i][j] = false;
  };

  dfs(dfs, start.first, start.second);
  if (isOk)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}