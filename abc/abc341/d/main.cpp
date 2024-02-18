#include <vector>
#include <algorithm>
#include <iostream>
#include <atcoder/all>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e18
using ll = long long;

int main() {
  ll n, m, k;
  cin >> n >> m >> k;

  // n, mの最小公倍数
  ll l = lcm(n, m);

  auto f = [&] (ll x) -> bool {
    ll res = (x / n) + (x / m) - (x / l)*2;

    return res >= k;
  };

  ll wa = 0;
  ll ac = 1e18;
  while(ac - wa > 1) {
    ll x = (wa + ac) / 2;
    if (f(x)) ac = x; else wa = x;
  }

  cout << ac << endl;

  return 0;
}