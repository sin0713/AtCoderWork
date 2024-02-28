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
  ll a, m, l, r;
  cin >> a >> m >> l >> r;

  // 基点を0にする
  l -= a; r -= a;

  // 正の数同士の関係にする
  if (l < 0) {
    ll x = -l / m + 1; 
    l += m * x; r += m * x;
  }

  auto f = [&] (ll x) { return x / m; };

  ll ans = f(r) - f(l-1);
  cout << ans << endl;
  return 0;
}