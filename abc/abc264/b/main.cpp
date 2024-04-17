#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int r, c;
  cin >> r >> c;

  int dist = max(abs(r - 8), abs(c - 8));
  if (dist % 2) cout << "black" << endl;
  else cout << "white" << endl;
  return 0;
}