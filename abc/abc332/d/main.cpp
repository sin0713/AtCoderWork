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

  queue<vvi> q;
  map<vvi, int> dist;
  auto push = [&] (vvi &state, int d) {
    if (dist.count(state)) return;

    dist[state] = d;
    q.push(state);
  };

  push(a, 0);
  while(!q.empty()) {
    vvi state = q.front(); q.pop();
    int current_dist = dist[state]; 

    rep(i, h-1) {
      vvi ns = state;
      swap(ns[i], ns[i+1]);
      push(ns, current_dist+1);
    }

    rep(j, w-1) {
      vvi ns = state;
      rep(i, h) {
        swap(ns[i][j], ns[i][j+1]);
      }
      push(ns, current_dist+1);
    }
  }

  if (dist.count(b)) cout << dist[b] << endl;
  else cout << -1 << endl;

  return 0;
}