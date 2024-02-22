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
  string s;
  cin >> s;

  int m = 128;
  vector<int> cnt(m);
  for(char& c : s) {
    cnt[c]++;;
  }

  int mx = 0;
  for (int& x : cnt) {
    mx = max(mx, x);
  }

  rep(i, m) {
    if (cnt[i] == mx) {
      cout << (char)i << endl;
      return 0;
    }
  }
  return 0;
}