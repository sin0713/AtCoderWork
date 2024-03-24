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
  int x = 0;
  rep(i, m) {
    int a, c; char b, d;
    cin >> a >> b >> c >> d;
    a--; c--;
    // 既に同じ連結成分に辺を張るということはサイクルができたということ
    if (uf.same(a, c)) x++;     
    else uf.merge(a, c);
  }

  int y = uf.groups().size() - x;

  printf("%d %d\n", x, y);
  return 0;
}