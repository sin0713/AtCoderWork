#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, k;
  cin >> n >> k;

  rep(i, n) {
    int a;
    cin >> a;

    if (a % k == 0) {
      int ans = a / k;
      cout << ans << " ";
    }
  }
  cout << endl;
  return 0;
}