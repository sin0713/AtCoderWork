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
  string s;
  cin >> n >> q >> s;

  vector<int> cnt(n);
  rep(i, n-1) {
    if (s[i] == s[i+1]) {
      cnt[i+1]++;
    }
  }
  vector<int> d(n+1);
  rep(i, n) d[i+1] = cnt[i] + d[i];

  rep(i, q) {
    int l, r;
    cin >> l >> r;

    cout << d[r] - d[l] << '\n';
  }

  return 0;
}