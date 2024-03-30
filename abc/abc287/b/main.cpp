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

  int lt = 3; int ls = 6;
  vector<string> s_list(n);
  rep(i, n) {
    string s;
    cin >> s;

    string ns;
    rep(j, ls) {
      if (j < lt) continue;

      ns.push_back(s[j]);
    }
    s_list[i] = ns;
  }
  set<string> t_set;
  rep(i, m) {
    string t;
    cin >> t;
    t_set.insert(t);
  }

  int ans = 0;
  rep(i, n) {
    if (t_set.count(s_list[i])) ans++;
  }
  cout << ans << endl;
  return 0;
}