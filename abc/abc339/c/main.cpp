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
  int n;
  cin >> n;
  vector<ll> a(n);
  ll total = 0;
  rep(i, n) {
    cin >> a[i];
    total += a[i];
  }

  auto check = [&] (ll value) -> bool {
    ll res = value;
    rep(i, n) {
      res += a[i];
      if (res < 0) break;
    }

    return res >= 0;
  };

  ll wa = 0; 
  ll ac = INF;
  while(ac - wa > 1) {
    ll value = (ac + wa) / 2;
    if (check(value)) ac = value; else wa = value;
  }

  if (ac == 1 && check(0)) ac = 0;
  cout << ac+total << endl;

  return 0;
}