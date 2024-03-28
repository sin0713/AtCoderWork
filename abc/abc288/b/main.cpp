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

  vector<string> s(n);
  rep(i, n) cin >> s[i];

  vector<string> ans;
  rep(i, k) ans.push_back(s[i]);
  sort(ans.begin(), ans.end());

  rep(i, k) cout << ans[i] << endl;
  return 0;
}