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
    int a, b;
    cin >> a >> b;
    a--; b--;
    uf.merge(a, b);
  }

  ll sum = 0;
  rep(i, n) {
    if (uf.leader(i) != i) continue;

    ll s = uf.size(i);
    sum += s*(s-1)/2;
  }

  ll ans = sum - m;
  cout << ans << endl;
  return 0;
}