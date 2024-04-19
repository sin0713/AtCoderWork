#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <atcoder/all>
#include <math.h>

using namespace std;
using vvi = vector<vector<int>> ;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF (1 << 30)

int main() {
  int h, w;
  cin >> h >> w;

  vector<vector<int>> a(h, vector<int>(w));
  vector<vector<int>> b(h, vector<int>(w));
  rep(i, h) {
    rep(j, w) {
      cin >> a[i][j];
    }
  }
  rep(i, h) {
    rep(j, w) {
      cin >> b[i][j];
    }
  }

  vector<int> order_h(h);
  rep(i, h) order_h[i] = i;
  vector<int> order_w(w);
  rep(i, w) order_w[i] = i;

  do {
      vector nv = a;
      rep(i, h) {
        rep(j, w) {
          nv[i][j] = a[order_h[i]][j];
        }
      }
    do {
      rep(j, w) {
        rep(i, h) {
          nv[i][j] = a[i][order_w[j]];
        }
      }
    } while(next_permutation(order_w.begin(), order_w.end()))
  } while(next_permutation(order_h.begin(), order_h.end()))
  return 0;
}