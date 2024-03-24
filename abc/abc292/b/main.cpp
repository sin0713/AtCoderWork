#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, q;
  cin >> n >> q;

  vector<int> players(n);
  rep(i, q) {
    int c, x;
    cin >> c >> x;
    x--;

    if (c == 1 || c == 2) {
      players[x] += c;
      continue;
    }

    if (players[x] > 1) {
      cout << "Yes" << '\n';
    } else {
      cout << "No" << '\n';
    }
  }
  return 0;
}