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

  const int mx = 10;
  vector<ll> ans;
  auto dfs = [&] (auto dfs, int d, ll val) -> void {
    if (d > mx) return;
    ans.push_back(val);
    
    for (int i = -1; i <= 1 ; i++) {
      int add = (val % 10) + i; 
      if (add >= 0 && add < 10) dfs(dfs, d+1, val * 10 + add);
    }
  };

  for (int i = 1; i < 10; i++) {
    dfs(dfs, 1, i);
  }

  sort(ans.begin(), ans.end());
  cout << ans[k-1] << endl;
  return 0;
}