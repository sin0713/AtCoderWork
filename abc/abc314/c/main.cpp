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
  string s;
  cin >> n >> m >> s;

  vector<int> c(n);
  rep(i, n) {
    int color;
    cin >> color;
    color--;
    c[i] = color;
  }

  vector<vector<int>> c_index_list(m);
  rep(i, n) {
    c_index_list[c[i]].push_back(i);
  } 

  string ans = s;
  rep(i, m) {
    int size = c_index_list[i].size();
    rep(j, size) {
      ans[c_index_list[i][(j+1) % size]] = s[c_index_list[i][j]];
    }
  }

  cout << ans << endl;
  return 0;
}