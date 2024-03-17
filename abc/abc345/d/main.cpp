#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, h, w;
  cin >> n >> h >> w;

  vector<P> ab(n);
  rep(i, n) cin >> ab[i].first >> ab[i].second;

  auto dfs = [&] (auto dfs, vector<string> board,  vector<bool> used) {
    int si = -1; int sj = -1; 
    rep(i, h) rep(j, w) {
      if (board[i][j] == '.' && si == -1) {
        si = i; sj = j;
      }
    }

    if (si == -1) {
      return true;
      cout << "Yes" << endl;
    }

  };

  return 0;
}