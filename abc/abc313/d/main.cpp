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
  int n, k;
  cin >> n >> k;

  vector<int> a(n);

  auto f = [&] (vector<int> x) -> int {
    rep(i, k) x[i]++;

    cout << '?';
    rep(i, k) { cout << ' ' << x[i]; }
    cout << endl;

    int res;
    cin >> res;
    return res;
  };

  // 先頭k+1の要素を確定させる
  vector<int> v(k+1);
  int t = 0;
  rep(i, k+1) {
    vector<int> b;
    rep(j, k+1) if (i != j) b.push_back(j);

    v[i] = f(b);
    t ^= v[i];
  }

  rep(i, k+1) {
    a[i] = t^v[i];
  }

  // k-1個目までの合計を出す
  t = 0;
  rep(i, k-1) { t ^= a[i]; }

  // k+2個目以降を確定させる
  for (int i = k+1; i < n; i++) {
    vector<int> x;
    rep(j, k-1) x.push_back(j);
    x.push_back(i);
    int res = f(x);

    a[i] = t ^ res;
  }

  cout << '!'; 
  rep(i, n) {
    cout << ' ' << a[i];
  }
  cout << endl;
  return 0;
}