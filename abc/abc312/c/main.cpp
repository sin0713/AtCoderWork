#include <vector>
#include <algorithm>
#include <iostream>
#include <atcoder/all>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  vector<int> b(m);
  rep(i, n) cin >> a[i];
  rep(i, m) cin >> b[i];

  sort(a.begin(), a.end());
  sort(b.rbegin(), b.rend());

  auto f = [&] (ll x) -> bool {
    int a_cnt = 0;
    int b_cnt = 0;

    rep(i, n) {
      if (x >= a[i]) a_cnt++;
      if (x < a[i]) break;
    }

    rep(i, m) {
      if (x <= b[i]) b_cnt++;
      if (x > b[i]) break;
    }

    return a_cnt >= b_cnt;
  };

  const ll INF = 1e10;
  ll wa = 0;
  ll ac = INF;
  while((ac - wa) > 1) {
    ll key = (ac + wa) / 2;
    if (f(key)) ac = key; else wa = key;
  }

  cout << ac << endl;
  return 0;
}