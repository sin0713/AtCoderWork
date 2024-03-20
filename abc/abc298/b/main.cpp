#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

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

int main()
{
  int n;
  cin >> n;

  vector<vector<int>> a(n, vector<int>(n));
  vector<vector<int>> b(n, vector<int>(n));
  rep(i, n) rep(j, n) cin >> a[i][j];
  rep(i, n) rep(j, n) cin >> b[i][j];
  cout << endl;

  auto isOk = [&]() -> bool {
    rep(i, n) {
      rep(j, n) {
        if (a[i][j] == 1 && b[i][j] != 1) {
          return false;
        }
      }
    }
    return true;
  };

  string ans = "No";
  rep(i, 4) {
    rotate(a);
    if (isOk())  {
      ans = "Yes";
      break;
    }
  }

  cout << ans << endl;
  return 0;
}