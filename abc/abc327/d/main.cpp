#include <vector>
#include <algorithm>
#include <iostream>
#include <atcoder/all>
#include <math.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF (1 << 30)

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> a(m);
  vector<int> b(m);
  rep(i, m) cin >> a[i], a[i]--;
  rep(i, m) cin >> b[i], b[i]--;

  vector<vector<int>> graph(n);
  rep(i, m) {
    graph[a[i]].push_back(b[i]);
    graph[b[i]].push_back(a[i]);
  }

  vector<int> color(n, -1);
  auto dfs = [&] (auto dfs, int position, int value) -> bool {
    if (color[position] != -1) return color[position] == value;

    color[position] = value;
    for (int &pos : graph[position]) {
      if (!dfs(dfs, pos, value ^ 1)) return false;
    }
    return true;
  };

  rep(i, n) {
    if (color[i] == -1) {
      if (!dfs(dfs, i, 0)) {
        cout << "No" << endl;
        return 0;
      }
    }
  }

  cout << "Yes" << endl;

  return 0;
}