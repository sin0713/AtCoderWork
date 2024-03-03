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
  ll n;
  cin >> n;

  vector<ll> d;
  for (ll i = 1; ; i++) {
    ll res = i * i * i;
    if (res > INF) {
      break;
    }

    string res_str = to_string(res);
    string res_str_rev = res_str;
    reverse(res_str_rev.begin(), res_str_rev.end());
    if (res_str == res_str_rev) {
      d.push_back(res);
    }
  }

  ll ans = 1;
  rep(i, (int)d.size()) {
    if (d[i] <= n) {
      ans = d[i];
    }
  }

  cout << ans << endl;
  return 0;
}