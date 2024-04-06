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
  vector<int> c(n);
  rep(i, n) cin >> a[i] >> c[i];

  map<int, int> mp;
  rep(i, n) {
    if (mp.count(c[i])) {
      mp[c[i]] = min(mp[c[i]], a[i]);
      continue;
    }
    mp[c[i]] = a[i];
  }

  int ans = 0;
  for (auto [cc, aa] : mp) {
    ans = max(ans, aa);
  }

  cout << ans << endl;
  return 0;
}