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

  rep(i, n+1) {
    rep(j, n+1) {
      rep(k, n+1) {
        if (i + j + k >= n+1) continue;
        cout << i << " " << j << " " << k << '\n';
      }
    }
  }
  return 0;
}