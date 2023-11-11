#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int H;
int W;
vector<string> table;

void dfs(int y, int x) {
  // '#'を探索済みにする
  table[y][x] = '.';

  // 隣接マス探索
  for (int i = -1; i < 2; i++) {
    for (int j = -1; j < 2; j++) {
      int next_x  = x + j;
      int next_y  = y + i;
      if (next_x < 0 || next_x >= W) continue;
      if (next_y < 0 || next_y >= H) continue;

      if (table[next_y][next_x] == '#') {
        dfs(next_y, next_x);
      }
    }
  }
}

int main() {
  cin >> H >> W;
  table.resize(H);
  rep(i, H) cin >> table[i];

  int ans = 0;
  rep(i, H) {
    rep(j, W) {
      if (table[i][j] == '.') continue;

      ans++;
      dfs(i, j);
    }
  }

  cout << ans << endl;

  return 0;
}