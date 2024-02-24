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

  vector<int> cnt(128);
  rep(i, s.size()) {
    cnt[s[i]]++;
  }

  char target = 'a';
  rep(i, cnt.size()) {
    if (cnt[i] == 1) {
      target = i;
      break;
    }
  }

  rep(i, s.size()) {
    if (s[i] == target) {
      cout << i+1 << endl;
      return 0;
    }
  }

  return 0;
}