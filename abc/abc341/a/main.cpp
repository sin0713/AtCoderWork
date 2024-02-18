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
  rep(i, n + n + 1) {
    if (i % 2 == 1) {
      cout << '0';
      continue;
    }
    cout << '1';
  }
  cout << endl;
  return 0;
}