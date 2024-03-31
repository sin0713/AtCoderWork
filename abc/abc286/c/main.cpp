#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  string s;
  cin >> s;

  ll ans = 1e18;
  rep(ai, n) {
    string t = s;
    rotate(t.begin(), t.begin()+ai, t.end());
    ll now = (ll)ai*a;
    for (int l = 0, r = n-1; l < r; l++, r--) {
      if (t[l] != t[r]) now += b;
    }
    ans = min(ans, now);
  }

  cout << ans << endl;
  return 0;
}