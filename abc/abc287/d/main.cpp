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

  int n = t.size();
  vector<bool> pre(n+1, false);
  vector<bool> suf(n+1, false);

  pre[0] = true;
  suf[0] = true;
  rep(i, n) {
    if (s[i]==t[i] || s[i] == '?' || t[i] == '?') {
      pre[i+1] = true;
    } else break;
  }

  reverse(s.begin(), s.end());
  reverse(t.begin(), t.end());
  rep(i, n) {
    if (s[i]==t[i] || s[i] == '?' || t[i] == '?') {
      suf[i+1] = true;
    } else break;
  }

  rep(i, n+1) {
    if (pre[i] && suf[n-i]) {
      cout << "Yes" << '\n';
    }
    else {
      cout << "No" << '\n';
    }
  }
  return 0;
}