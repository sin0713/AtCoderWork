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

  vector<string> s(n);
  rep(i, n) cin >> s[i]; 

  auto check = [&] (int i, int j)-> bool {
    for (int k = i; k < i+4; k++) {
      for (int l = j; l < j+4; l++) {
        if (k == i+4-1 || l == j+4-1) {
          if (s[k][l] != '.') return false;
        } else {
          if (s[k][l] != '#') return false;
        }
      }
    }

    for (int o = i+5; o < i+9; o++) {
      for (int p = j+5; p < j+9; p++) {
        if (o == i+5 || p == j+5) {
          if (s[o][p] != '.') return false;
        } else {
          if (s[o][p] != '#') return false;
        }
      }
    }

    return true;
  };

  rep(i, n - 8) {
    rep(j, m - 8) {
      if (check(i, j)) cout << i+1 << ' ' << j+1 << '\n';
    }
  }

  return 0;
}