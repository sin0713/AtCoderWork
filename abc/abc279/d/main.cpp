#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  ll a, b;
  cin >> a >> b;

  ll l = 0, r = 1e18;
  auto f = [&](ll x) -> double {
    double res = (double)x*b + a/sqrt(x+1);
    return res;
  };

  while(l+3 <= r) {
    ll c1 = (l*2+r)/3;
    ll c2 = (l+r*2)/3;
    if (f(c1) > f(c2)) l = c1; else r = c2;
  }

  double ans = min({f(l), f(l+1), f(r)});
  printf("%.10f\n", ans);
  return 0;
}