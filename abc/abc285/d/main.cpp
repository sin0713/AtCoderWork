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
  bool ok = true;
  auto dfs = [&] (auto dfs, string v, int cnt) -> void {
    if (seen.count(v)) {
      if (seen[v] == cnt) {
        ok = false;
        return;
      }

      return;
    }

    seen.insert({v, cnt});
    if (to.count(v)) {
      dfs(dfs, to[v], cnt);
    }
  };

  for (int i = 0; i < n; i++) {
    dfs(dfs, s[i], i);
    if (!ok) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  return 0;
}