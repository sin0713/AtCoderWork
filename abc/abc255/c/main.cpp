#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  ll x, a, d, n;
  cin >> x >> a >> d >> n;

  if (d == 0) {
    cout << abs(x-a) << endl;
    return 0;
  }

  if (d < 0) {
    a = a+(n-1)*d;
    d = -d;
  }

  auto f = [&](ll i) {
    if (i < 0) i = 0;
    if (i >= n) i = n-1;
    return abs(x-(a+d*i));
  };
  ll i = (x-a)/d;

  cout << min(f(i), f(i+1)) << endl;;
  return 0;
}