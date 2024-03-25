#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;

  vector<P> es;
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    es.emplace_back(u, v);
  }
  
  dsu uf(n);
  for (auto [a, b] : es) uf.merge(a, b);

  vector<int> num_v(n); // 連結成分内の頂点数
  vector<int> num_e(n); // 連結成分内の辺数
  rep(i, n) num_v[uf.leader(i)]++;
  for (auto [u, v] : es) num_e[uf.leader(u)]++;

  rep(i, n) {
    if (num_v[i] != num_e[i]) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  return 0;
}