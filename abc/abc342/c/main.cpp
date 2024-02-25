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
  int n, q;
  string s;
  cin >> n >> s >> q;

  int m = 26;
  vector<int> memo(m);
  for (char c = 'a'; c <= 'z'; c++) {
    memo[c - 'a'] = c;
  }

  rep(i, q) {
    char c, d;
    cin >> c >> d;

    rep(i, m) {
      if (memo[i] == c) {
        memo[i] = d;
      }
    }
  }
  

  string ans = s;
  rep(i, s.size()) {
    ans[i] = memo[s[i] - 'a'];
  }

  cout << ans << endl;
  return 0;
}