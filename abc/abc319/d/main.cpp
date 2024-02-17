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

int main()
{
  int n, m;
  cin >> n >> m;

  vector<int> l(n);
  rep(i, n) {
    cin >> l[i];
  }

  ll left = 0;
  ll right = 1e15;
  while (abs(right - left) > 1) {
    ll wj = (left + right) / 2;
    auto f = [&](ll w) -> bool {
      ll rem = 0;
      int line = 0;
      rep(i, n) {
        if (rem >= l[i] + 1) {
          rem -= l[i] + 1;
          continue;
        }

        line++;
        rem = w - l[i];
        if (rem<0) return false;
      }

      return line <= m;
    };

    if (f(wj)) right = wj; else left = wj;
  }

  cout << right << endl;

  return 0;
}