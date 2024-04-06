#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  string s, t;
  cin >> s >> t;
  int ns = s.size();
  int nt = t.size();

  for (int i = 0; ns-i >= nt; i++) {
    bool ok = true;
    rep(j, nt) {
      if (s[i+j] != t[j]) {
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
  return 0;
}