#include <atcoder/all>
#include <bits/stdc++.h>

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;
using P = pair<int, int>;

struct Sheet {
  int h, w;
  vector<string> data;

  void input() {
    cin >> h >> w;
    data.resize(h);
    rep(i, h) cin >> data[i];
  }

  bool write(int pi, int pj, Sheet& target) {
    rep(i, h) {
      rep(j, w) {
        if (data[i][j] == '.') continue;
        int move_i = i+pi;
        int move_j = j+pj;
        if (move_i < 0 || move_i >= target.h || move_j < 0 || move_j >= target.w) {
          return false;
          continue;
        }

        target.data[move_i][move_j] = data[i][j];
      }
    }
    return true;
  }

  void clear() {
    rep(i, h) rep(j, w) data[i][j] = '.';
  }
};
 
int main() {
  Sheet a, b, x;
  a.input();
  b.input();
  x.input();

  for (int ai = -x.h; ai < x.h; ai++) {
    for (int aj = -x.w; aj < x.w; aj++) {
      for (int bi = -x.h; bi < x.h; bi++) {
        for (int bj = -x.w; bj < x.w; bj++) {
          Sheet c = x; c.clear();
          if (!a.write(ai, aj, c)) continue;
          if (!b.write(bi, bj, c)) continue;

          if (c.data == x.data) {
            cout << "Yes" << endl;
            return 0;
          }
        }
      }
    }
  }

  cout << "No" << endl;
  return 0;
}