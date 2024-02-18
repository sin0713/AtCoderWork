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

  vector<vector<int>> d(n, vector<int>(n+1));
  rep(i, n-1) {
    for (int j = i+1; j < n; j++) {
      cin >> d[i][j];
      d[j][i] = d[i][j];
    }
  }

  // 重み無し頂点追加
  // あまりの選択を作るため
  if (n % 2 == 1) { n++; } 

  ll ans = 0;
  vector<bool> used(n); 
  auto f = [&] (auto f, ll w) -> void {
    ans = max(ans, w);
    int i = 0;
    while(i < n && used[i]) i++;
    if (i == n) return; // usedの中身が全てtrue
    used[i] = true;
    for (int j = i+1; j < n; j++) {
      if (used[j]) continue;

      used[j] = true;
      f(f, w+d[i][j]);
      used[j] = false;
    }
    used[i] = false;
  };

  f(f, 0);
  cout << ans << endl;
  return 0;
}