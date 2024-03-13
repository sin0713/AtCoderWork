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
  rep(i, n) cin >> s[i];

  rep(i, n) {
    rep(j, n) {
      if (i == j) continue;

      string concat_str = s[i] + s[j];
      string concat_str_rev = concat_str;
      reverse(concat_str_rev.begin(), concat_str_rev.end());
      if (concat_str == concat_str_rev) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;
  return 0;
}