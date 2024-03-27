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

  dsu uf(n);
  rep(i, m) {
    int a;
    cin >> a;
    a--;
    uf.merge(a, a + 1);
  }

  auto groups = uf.groups();
  for (auto &group : groups) {
    sort(group.rbegin(), group.rend());
  }

  sort(groups.begin(), groups.end());
  for (auto &group : groups) {
    for (int x : group) {
      cout << x+1 << " ";
    }
  }
  cout << endl;

  return 0;
}