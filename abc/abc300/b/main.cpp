#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main()
{
  int h, w;
  cin >> h >> w;

  vector<string> a(h);
  vector<string> b(h);
  rep(i, h) cin >> a[i];
  rep(i, h) cin >> b[i];

  vector<string> c = a;
  auto shift_left = [&]() {
    vector<string> x = c;
    rep(i, h) {
      rep(j, w) {
        if (j == w - 1) {
          c[i][j] = x[i][0];
          continue;
        }
        c[i][j] = x[i][j + 1];
      }
    }
  };

  auto shift_up = [&] () {
    vector<string> x = c;
    rep(j, w) {
      rep(i, h) {
        if (i == h - 1) {
          c[i][j] = x[0][j];
          continue;
        }
        c[i][j] = x[i+1][j];
      }
    }
  };

  rep(i, h) {
    rep(j, w) {
      shift_left();
      if (c == b) {
        cout << "Yes" << endl; 
        return 0;
      }
    }
    shift_up();
  }

  cout << "No" << endl;
  return 0;
}