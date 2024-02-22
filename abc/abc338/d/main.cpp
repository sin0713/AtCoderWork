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
  int n, m;
  cin >> n >> m;

  vector<int> x(m);
  rep(i, m) { cin >> x[i]; x[i]--;}

  vector<ll> d(n+1);

  auto add = [&] (int l, int r, int value) {
    d[l] += value;
    d[r] -= value;
  };
  rep(i, m-1) {
    int s = x[i]; int t = x[i+1];
    if (s > t) swap(s, t);
    int a = t - s;
    int b = n - a;

    add(0, s, a);
    add(s, t, b);
    add(t, n, a);
  }

  rep(i, n) d[i+1] += d[i]; 

  int ans = *min_element(d.begin(), d.begin()+n);
  cout << ans << endl;
  return 0;
}