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

  int cnt = 0;
  rep(i, h) {
    rep(j, w) {
      if (a[i][j] == b[i][j]) continue;

      bool is_found = false;
      rep(k, h) {
        rep(l, w) {
          if (a[k][l] != b[i][j]) continue;

          is_found = true;


        }
      }








    }
  }









  return 0;
}