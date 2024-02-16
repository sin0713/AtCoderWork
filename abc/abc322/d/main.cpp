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
  int n = 3;
  int m = 4;

  vector p(n, vector<string>(m));
  rep(i, n) {
    rep(j, m) {
      cin >> p[i][j];
    }
  }

  // 平行移動x回転の結果グリッドを格納する配列
  vector<vector<vector<string>>> s(n);

  // 平行移動(x方向-4~4, y方向-4~4 8x8=64パターン)と回転処理(4種類)
  rep(pi, n) {
    rep(ri, 4) {
      // 平行移動
      for (int yi = -m; yi < m; yi++) {
        for (int xi = -m; xi < m; xi++) {
          bool ok = true;
          vector<string> np(m, string(m, '.')); // 平行移動結果
          rep(i, m) {
            rep(j, m) {
              if (p[pi][i][j] == '.') continue;
              int di = i + yi;
              int dj = j + xi;

              if (di < 0 || dj < 0 || di > m-1 || dj > m-1) {
                // 範囲外への平行移動のためNG
                ok = false;
                continue;
              }
              np[di][dj] = '#';
            }
          }
          if (!ok) continue;
          s[pi].push_back(np);
        }
      }

      // 回転処理
      vector<string> pre = p[pi];
      rep(i, m) {
        rep(j, m) {
          p[pi][i][j] = pre[m - 1 -j][i];
        }
      }
    }
  }


  vector succee_grid(m, vector<int>(m, 1));
  for (auto &s0 : s[0]) {
    for (auto &s1 : s[1]) {
      for (auto &s2 : s[2]) {
        vector<vector<int>> cnt(m, vector<int>(m, 0));
        auto put = [&](vector<string>& poly) {
          rep(i, m) {
            rep(j, m) {
              if (poly[i][j] == '#') {
                cnt[i][j]++;
              }
            }
          }
        };
        put(s0);
        put(s1);
        put(s2);

        if (cnt == succee_grid) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }

  cout << "No" << endl;

  return 0;
}