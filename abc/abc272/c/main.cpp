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

  vector<int> a(n);
  rep(i, n) cin >> a[i];

  vector<int> evens, odds;
  rep(i, n) {
    if (a[i] % 2) {
      evens.push_back(a[i]);
    } else {
      odds.push_back(a[i]);
    }
  }

  sort(evens.begin(), evens.end());
  sort(odds.begin(), odds.end());
  int es = evens.size();
  int os = odds.size();
  if (es < 2 && os < 2) {
    cout << -1 << endl;
    return 0;
  }

  ll ans = 0;
  if (es >= 2) {
    ll now = (ll)evens[es-1]+evens[es-2];
    ans = max(ans, now);
  }
  if (os >= 2) {
    ll now = (ll)odds[os-1]+odds[os-2];
    ans = max(ans, now);
  }

  cout << ans << endl;
  return 0;
}