#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int t;
  cin >> t;
  rep(i, t) {
    int n;
    cin >> n;

    int ans = 0;
    rep(i, n) {
      int a;
      cin >> a;
      if (a % 2) ans++;
    }
    cout << ans << '\n';
  }
  return 0;
}