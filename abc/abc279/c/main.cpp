#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using p = pair<int, int>;

int main() {
  int h, w;
  cin >> h >> w;

  vector<string> s(h);
  vector<string> t(h);
  rep(i, h) cin >> s[i];
  rep(i, h) cin >> t[i];

  vector<string> ns(w, string(h, ' '));
  vector<string> nt(w, string(h, ' '));

  rep(j, w) {
    rep(i, h) {
      ns[j][i] = s[i][j];
      nt[j][i] = t[i][j];
    }
  }
  sort(ns.begin(), ns.end());
  sort(nt.begin(), nt.end());
  cout << ((ns == nt) ? "Yes" : "No") << endl;
  return 0;
}