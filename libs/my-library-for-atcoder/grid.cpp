#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;


/*
  グリッド回転
  @param grid 回転させたいグリッド
  参照渡しなので、引数のグリッドを上書きする
*/
void rotate(vector<vector<int>>& grid)
{
  vector<vector<int>> copy = grid;
  int n = grid.size();
  rep(i, n) {
    rep(j, n) {
      grid[n-1-j][i] = copy[i][j];
    }
  }
}

int main() {

  return 0;
};