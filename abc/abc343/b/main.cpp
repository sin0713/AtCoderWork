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

  vector<vector<int>> a(n, vector<int>(n));
  rep(i, n) rep(j, n) cin >> a[i][j];

  rep(i, n) {
    rep(j, n) {
      if (a[j][i] == 1) {
        cout << j + 1 << ' '; 
      } 
    }
    cout << endl;
  }
  
  return 0;
}