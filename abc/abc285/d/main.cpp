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

  vector<string> s(n);
  vector<string> t(n);
  rep(i, n) { cin >> s[i] >> t[i]; }

  map<string, string> to;
  rep(i, n) { to[s[i]] = t[i]; }

  map<string, int> seen;
  auto dfs = [&] (auto dfs, string v, int cnt) -> void {
    if (seen.count(v)) return;

    seen.insert({v, cnt});
    dfs(dfs, to[v], cnt);
  };

  for (int i = 0; i < n; i++) {
    dfs(dfs, to[s[i]], i);

    if (seen.count(s[i]) && seen[s[i]] == i) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  return 0;
}