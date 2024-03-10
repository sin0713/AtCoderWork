#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
int main() {
  int n;
  cin >> n;

  vector<string> a(n);
  rep(i, n) cin >> a[i];
  vector<string> b = a;
  vector<P> p = {
    {0, 0},
    {0, n-1},
    {n-1, n-1},
    {n-1, 0}
  };

  rep(i, 4) {
    int ai = p[i].first; 
    int aj = p[i].second;
    rep(j, n-1) {
      ai += dy[i]; aj += dx[i];
      b[ai][aj] = a[p[i].first][p[i].second];
      p[i].first += dy[i]; p[i].second += dx[i];
    }
  }

  rep(i, n) {
    rep(j, n) cout << b[i][j];
    cout << endl;
  }
  return 0;
}