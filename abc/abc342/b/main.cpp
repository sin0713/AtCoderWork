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
  vector<int> order(n);
  rep(i, n) {
    int p;
    cin >> p;
    p--;
    order[p] = i;
  }

  int q;
  cin >> q;

  vector<int> res(q);
  rep(i, q) {
    int a, b;
    cin >> a >> b;
    if (order[a - 1] < order[b - 1]) {
      res[i] = a;
    } else {
      res[i] = b;
    }
  }

  rep(i, q) {
    cout << res[i] << endl;
  }

  return 0;
}