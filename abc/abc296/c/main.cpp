#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, x; 
  cin >> n >> x;

  vector<int> a(n);
  rep(i, n) cin >> a[i];

  unordered_map<int, int> mp;
  rep(i, n) { mp[a[i]]++; }

  string ans = "No";
  for (auto [k, v] : mp) {
    ll value = k + x;
    if (mp.count(value)) {
      ans = "Yes";
      break;
    }
  }

  cout << ans << endl;
  return 0;
}