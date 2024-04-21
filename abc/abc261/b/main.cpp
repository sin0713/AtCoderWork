#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<string> a(n);
  rep(i, n) cin >> a[i];

  bool ans = true;
  rep(i, n) {
    bool ok = true;
    rep(j, n) {
      if (i == j) continue;

      if (a[i][j] == 'W' && a[j][i] != 'L') ok = false;       
      if (a[i][j] == 'L' && a[j][i] != 'W') ok = false;
      if (a[i][j] == 'D' && a[j][i] != 'D') ok = false;
      if (!ok) break;
    }
    if (!ok) {
      ans = ok;
      break;
    }
  }

  cout << (ans ? "correct" : "incorrect") << endl;
  return 0;
}