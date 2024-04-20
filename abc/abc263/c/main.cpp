#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> ans;
  for (int bit = 0; bit < (1<<m); bit++) {
    vector<int> res;
    rep(i, m) {
      if (bit & (1<<i)) res.push_back(i+1);
    }

    if (res.size() != n) continue;
    ans.push_back(res);
  }

  sort(ans.begin(), ans.end());
  for (auto v : ans) {
    rep(i, n) {
      cout << v[i] << " ";
    }
    cout << "\n";
  }

  return 0;
}