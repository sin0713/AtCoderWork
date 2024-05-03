#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

void chmax(int& x, int y) { x = max(x, y); }

int main() {
  int n;
  cin >> n;
  vector<P> pairs(n);
  rep(i, n) cin >> pairs[i].first >> pairs[i].second;

  
  sort(pairs.begin(), pairs.end());

  vector<P> ans;
  for(auto [l, r] : pairs) {
    if (ans.size() == 0 || ans.back().second < l) {
      ans.emplace_back(l, r);
    } else {
      chmax(ans.back().second, r);
    }
  }
  for (auto& [l, r] : ans) {
    printf("%d %d\n", l, r);
  }
  return 0;
}