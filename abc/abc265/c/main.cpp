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

  vector<string> grid(h);
  rep(i, h) cin >> grid[i];

  int ci = 0;
  int cj = 0;
  vector seen(h, vector<bool>(w));
  while(true) {
    seen[ci][cj] = true;
    int ni = ci;
    int nj = cj;
    char now = grid[ci][cj];
    if (now == 'U') ni--;
    if (now == 'D') ni++;
    if (now == 'R') nj++;
    if (now == 'L') nj--;
    if (ni < 0 || ni >= h || nj < 0 || nj >= w) {
      printf("%d %d\n", ci+1, cj+1);
      return 0;
    };
    if (seen[ni][nj]) { break; }
    ci = ni; cj = nj;
  }

  cout << -1 << endl;
  return 0;
}