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

  vector<int> strengths(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    strengths[b]++;
  }

  int ans = -1;
  rep(i, n) {
    if (strengths[i] == 0) {
      if (ans != -1) {
        cout << -1 << endl; 
        return 0;
      } else {
        ans = i+1;
      }
    }
  }

  cout << ans << endl;
  return 0;
}