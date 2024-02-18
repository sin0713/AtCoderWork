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
  rep(i, n) cin >> a[i];

  vector<pair<int, int>> st(n-1);
  rep(i, n-1) {
    ll s, t;
    cin >> s >> t;
    st[i] = {s, t};
  }

  rep(i, n-1) {
    if (a[i] >= st[i].first) {
      ll num = a[i] / st[i].first;
      a[i + 1] += num * st[i].second;
    }
  }

  cout << a[n-1] << endl;

  return 0;
}