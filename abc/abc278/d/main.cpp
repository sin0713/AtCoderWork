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

  int q;
  cin >> q;

  int last_reset_value = -1;
  map<int, ll> mp;
  rep(i, q) {
    int type;
    cin >> type;
    if (type == 1) {
      int x;
      cin >> x;
      last_reset_value = x;
      mp.clear();
    } else if (type == 2) {
      int i, x;
      cin >> i >> x;
      i--;
      mp[i] += x;
    } else {
      int i; 
      cin >> i;
      i--;

      ll ans;
      if (last_reset_value < 0) { ans = a[i]; } 
      else { ans = last_reset_value; }
      if (mp.count(i)) ans += mp[i];
      cout << ans << '\n';
    }
  }
  return 0;
}