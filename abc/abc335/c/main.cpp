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
  cin >> n >> q;

  vector<pair<int, int>> d;
  for(int i = 1; i <= n; i++) {
    d.emplace_back(i, 0);
  }
  reverse(d.begin(), d.end());

  map<char, pair<int, int>> directions = 
  {
    {'U', {0, 1}}, 
    {'D', {0, -1}}, 
    {'R', {1, 0}}, 
    {'L', {-1, 0}}, 
  };

  rep(i, q) {
    char type;
    cin >> type; 

    auto [x, y] = d.back();
    if (type == '1') {
      char value;
      cin >> value;
      d.emplace_back(x+directions[value].first, y+directions[value].second);
      n++;
      continue;
    }

    int value; 
    cin >> value;
    ll s = d.size(); 
    cout << d[s - value].first << " " << d[s - value].second << '\n';
  }


  return 0;
}