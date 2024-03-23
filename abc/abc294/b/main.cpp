#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int h, w;
  cin >> h >> w;

  vector<vector<int>> a(h, vector<int>(w));
  rep(i, h) rep(j, w) {
    int x;
    cin >> x;
    x--;
    a[i][j] = x;
  } 

  rep(i, h) {
    rep(j, w) {
      if (a[i][j] < 0) {
        cout << '.';
        continue;
      }

      char c = 'A' + a[i][j];
      cout << c;
    }
    cout << '\n';
  }


  return 0;
}