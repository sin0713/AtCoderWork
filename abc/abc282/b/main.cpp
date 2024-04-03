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

  vector<string> s(n);
  rep(i, n) {
    cin >> s[i];
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      int now = 0;
      rep(k, m) {
        if (s[i][k] == 'o' || s[j][k] == 'o') now++;
      }
      if (now == m) ans++;
    }
  }

  cout << ans << endl;
  return 0;
}