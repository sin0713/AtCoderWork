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
  int n, d;
  cin >> n >> d; 

  vector<string> s(n);
  rep(i, n) cin >> s[i];

  int ans = 0;
  int cnt = 0;
  rep(j, d) {
    bool ok = true;
    rep(i, n) {
      if (s[i][j] == 'x') {
        ok = false;
        break;
      }
    }

    if (ok) { cnt++; } else { cnt = 0; }
    ans = max(ans, cnt);
  }

  cout << ans << endl;

  return 0;
}