#include <atcoder/all>
#include <bits/stdc++.h>
using namespace atcoder;

using namespace std;
using mint = modint998244353;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  vector<mint> b(n);
  rep(i, n) {
    ll res = 1;
    int x = a[i];
    while(x) res *= 10, x /= 10;
    b[i] = res;
  }

  mint ans = 0;
  rep(i, n) {
    ans += (mint(a[i]) * i);
  }


  mint s = 0;
  for (int i = n-1; i >= 0; i--) {
    ans += a[i] * s;
    s += b[i];
  }

  cout << ans.val() << endl;
  return 0;
}