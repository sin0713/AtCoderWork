#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int k;
  cin >> k;

  vector<ll> all;
  auto dfs = [&](auto dfs, ll val) -> void {
    all.push_back(val);

    int back = val % 10;
    if (back == 0) return;

    for (int i = back-1; i >= 0; i--) {
      dfs(dfs, val * 10 + i);
    }
  };

  for (int i = 1; i < 10; i++) {
    dfs(dfs, i);
  }

  sort(all.begin(), all.end());
  cout << all[k-1] << endl;
  return 0;
}
