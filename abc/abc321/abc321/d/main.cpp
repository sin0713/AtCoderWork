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
  int n, m, p;
  cin >> n >> m >> p;

  vector<int> a(n);
  vector<int> b(m);
  rep(i, n) cin >> a[i];
  rep(i, m) cin >> b[i];

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  vector<ll> s(m+1); 
  rep(i, m) {
    s[i+1] = s[i] + b[i];
  }

  ll ans = 0;
  rep(i, n) {
    int key = p - a[i];
    auto border_b = lower_bound(b.begin(), b.end(), key) - b.begin();
    ans += (a[i] * border_b) + s[border_b];
    ans += p * (m - border_b);
  }

  cout << ans << endl;

  return 0;
}