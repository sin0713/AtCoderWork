#include <vector>
#include <algorithm>
#include <iostream>
#include <atcoder/all>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e6
using ll = long long;

int main() {
  int n;
  cin >> n;

  vector<int> q(n);
  vector<int> a(n);
  vector<int> b(n);
  rep(i, n) cin >> q[i];
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];

  int a_cnt = 0;
  int mx = -1;
  while(true) {
    bool ok = true;
    vector<int> q_copy = q;
    rep(i, n) {
      if (q_copy[i] >= a[i] * a_cnt) {
        q_copy[i] -= a[i] * a_cnt;
        continue;
      }

      ok = false;
      break;
    }
    if (!ok) break;

    int b_cnt = INF; 
    rep(i, n) {
      if (b[i] == 0) continue;

      b_cnt = min(b_cnt, q_copy[i] / b[i]);
    }

    mx = max(mx, b_cnt+a_cnt);
    a_cnt++;
  }

  cout << mx << endl;
  return 0;
}