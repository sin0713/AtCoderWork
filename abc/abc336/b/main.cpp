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

  int ans = 0;
  while((n&1) == 0) {
    ans++;
    n >>= 1;
  }

  cout << ans << endl;
  return 0;
}