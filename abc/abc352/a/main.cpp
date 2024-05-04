#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, x, y, z;
  cin >> n >> x >> y >> z;

  if (x > y) swap(x, y);

  if (z >= x && z <= y) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}