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

  vector<int> ans(n, -1);
  map<int, vector<int>> mp;
  rep(ni, n) {
    int p;
    cin >> p;
    p--;

    auto it = mp.lower_bound(p);
    if (it == mp.end()) {
      // not found
      mp[p] = {p};
    } else {
      // found
      int i = it->first;
      mp[p] = move(mp[i]);
      mp[p].push_back(p);
      mp.erase(i);
    }

    if (mp[p].size() == k) {
      for (int num : mp[p]) {
        ans[num] = ni;
      }
      mp.erase(p);
    } 
  }

  rep(i, n) {
    if (ans[i] >= 0) ans[i]++;
    cout << ans[i] << '\n';
  }

  return 0;
}