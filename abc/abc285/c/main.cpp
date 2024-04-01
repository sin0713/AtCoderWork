#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;

  int n = s.size();
  const int m = 26;
  ll ans = 0;
  rep(i, n) {
    int num = s[i] - 'A' + 1;
    ans = ans * m + num;
  }

  cout << ans << endl;
  return 0;
}