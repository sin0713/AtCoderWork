#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

vector<int> dx = {0, 1, 1, 1, 0, -1, -1, -1};
vector<int> dy = {-1, -1, 0, 1, 1, 1, 0, -1};

int main() {
  int n;
  cin >> n;
  vector<string> a(n);
  rep(i, n) cin >> a[i];

  auto move = [&](int& v, int direc, bool is_x) {
    if (is_x) {  v += dx[direc]; } else { v += dy[direc]; }
    if (v == n) v = 0;
    if (v < 0)  v = n-1;
  };

  auto make = [&](int i, int j, int direc) {
      vector<char> res;
      res.push_back(a[i][j]);
      rep(ni, n-1) {
        move(i, direc, false);
        move(j, direc, true);
        res.push_back(a[i][j]);
      }

      return res;
  };

  auto convert = [](vector<char>& data) -> ll {
    ll res = 0;
    for (char c : data) {
      int num = c - '0';
      res = res*10 + num;
    }
    return res;
  };

  ll ans = 0;
  rep(si, n) {
    rep(sj, n) {
      rep(direc, 8) {
        vector<char> res = make(si, sj, direc);
        ans = max(ans, convert(res));
      }
    }
  }

  cout << ans << endl;
  return 0;
}