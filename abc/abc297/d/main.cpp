#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  ll a, b;
  cin >> a >> b;

  ll ans = 0;
  if (a < b) swap(a, b);

  while(b != 0) {
    ans += a / b;
    a %= b;
    if (a < b) swap(a, b);
  }

  cout << ans - 1 << endl;
  return 0;
}