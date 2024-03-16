#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

const vector<int> dx = {-1, 1, 1, -1};
const vector<int> dy = {-1, -1, 1, 1};

int main() {
  int h, w;
  cin >> h >> w;
  int n = min(h, w);

  vector<string> c(h);
  rep(i, h) cin >> c[i];

  auto out_grid = [&] (int i, int j) {
    return i < 0 || i >= h || j < 0 || j >= w;
  };

  auto cross_points = [&] (int i, int j) -> vector<P> {
    vector<P> res;
    rep(k, 4) {
      res.emplace_back(i + dy[k], j + dx[k]);
    }
    return res;
  };

  auto up_points = [&] (vector<P>& points) {
    rep(i, 4) {
      points[i].first += dy[i];
      points[i].second += dx[i];
    }
  };

  vector<int> ans(100);
  rep(i, h) {
    rep(j, w) {
      if (c[i][j] == '#') {
        vector<P> points = cross_points(i, j);
        bool ok = true;
        int size = 0;
        rep(k, n) {   // どこまで広げられるか見る
          rep(l, 4) { // 4箇所見る
            int pi = points[l].first;
            int pj = points[l].second;
            if (out_grid(pi, pj)) {
              ok = false;
              break;
            }

            if (c[pi][pj] != '#') {
              ok = false;
              break;
            }
          }
          if(!ok) { 
            if (size > 0) {
              ans[size-1]++; 
            }
            break;
          }
          size++;
          up_points(points);
        }
      }
    }
  }

  rep(i, n) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}