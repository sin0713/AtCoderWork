#include <vector>
#include <algorithm>
#include <iostream>
#include <atcoder/all>
#include <math.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF (1 << 30)

int main() {
  int n;
  cin >> n;
  vector<vector<int>> coordinate(n, vector<int>(4));
  rep(i, n) {
    rep(j, 4) {
      cin >> coordinate[i][j];
    }
  }

  vector<vector<int>> record(100, vector<int>(100, 0));
  int total = 0;
  rep(i, n) {
    int x_first = coordinate[i][0];
    int x_end = coordinate[i][1];
    int y_first = coordinate[i][2];
    int y_end = coordinate[i][3];
    for (int y = y_first; y < y_end; y++) {
      for (int x = x_first; x < x_end; x++) {
        if (record[x][y] == 0) {
          total++;
          record[x][y] = 1;
        }
      }
    }
  }

  cout << total << endl;

  return 0;
}