#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

const vector<int> dx = {
    0,  // 上
    1,  // 右上
    1,  // 右
    1,  // 右下
    0,  // 下
    -1, // 左下
    -1, // 左
    -1, // 左上
};

const vector<int> dy = {
    -1, // 上
    -1, // 右上
    0,  // 右
    1,  // 右下
    1,  // 下
    1,  // 左下
    0,  // 左
    -1, // 左上
};

int main()
{
  int h, w;
  cin >> h >> w;

  vector<string> s(h);
  rep(i, h)
  {
    cin >> s[i];
  }

  auto notOk = [&](int i, int j) -> bool
  {
    return i < 0 || i >= h || j < 0 || j >= w;
  };

  string snuke = "snuke";
  int m = 8;
  int mm = snuke.size();
  rep(i, h) {
    rep(j, w) {
      rep(k, m) {
        bool ok = true;
        int ni = i;
        int nj = j;
        rep(l, mm) {
          if (notOk(ni, nj) || s[ni][nj] != snuke[l] ) {
            ok = false;
            break;
          };

          ni += dy[k];
          nj += dx[k];
        }

        if (ok) {
          int ni = i;
          int nj = j;
          rep(i, mm) {
            cout << ni+1 << " " << nj+1 << endl;
            ni += dy[k];
            nj += dx[k];
          }
          return 0;
        }
      }
    }
  }

  return 0;
}