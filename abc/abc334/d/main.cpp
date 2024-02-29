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
  int n, q;
  cin >> n >> q;

  vector<int> r(n);
  rep(i, n) cin >> r[i];

  sort(r.begin(), r.end());

  vector<ll> d(n+1);
  rep(i, n) d[i+1] = d[i] + r[i];

  rep(i, q) {
    ll x;
    cin >> x;

    int ans = upper_bound(d.begin(), d.end(), x) - d.begin();
    ans--;
    cout << ans << '\n';
  }

  return 0;
}