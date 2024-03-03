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
  ll sum = 0;
  rep(i, n) {
    cin >> a[i];
    sum += a[i];
  }

  ll x = sum / n;
  ll r = sum % n;
  vector<ll> b(n, x);
  rep(i, r) { b[i]++; }

  sort(a.begin(), a.end());
  reverse(b.begin(), b.end());

  ll ans = 0;
  rep(i, n) {
    ans += abs(a[i] - b[i]);
  }

  cout << ans/2 << endl;

  return 0;
}