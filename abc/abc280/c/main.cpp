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

  int n = s.size();
  int ans = n;
  rep(i, n) {
    if (s[i] != t[i]) {
      ans = i;
      break;
    }
  }

  cout << ans+1 << endl;
  return 0;
}