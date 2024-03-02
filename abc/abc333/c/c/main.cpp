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
  n--;

  vector<ll> repunits;
  for (ll repunit = 1; repunit < ll(1e12); repunit = repunit * 10 + 1) {
    repunits.push_back(repunit);
  }

  set<ll> repunits_sum;
  for (auto a : repunits) {
    for (auto b : repunits) {
      for (auto c : repunits) {
        repunits_sum.insert(a + b + c);
      }
    }
  }

  vector <ll> res;
  for (auto a : repunits_sum) {
    res.push_back(a);
  }

  cout << res[n] << endl;
  return 0;
}