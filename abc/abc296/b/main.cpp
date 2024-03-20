#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n = 8;
  vector<vector<string>> board(n, vector<string>(n));
  vector<string> nums = {"8", "7", "6", "5", "4", "3", "2", "1"};
  vector<string> abcs = {"a", "b", "c", "d", "e", "f", "g", "h"};
  rep(i, n) {
    rep(j, n) { board[i][j] = abcs[j] + nums[i]; }
  }

  vector<string> s(n);
  rep(i, n) cin >> s[i];
  rep(i, n) {
    rep(j, n) {
      if (s[i][j] == '*') {
        cout << board[i][j] << endl;
        return 0;
      }
    }
  }

  return 0;
}