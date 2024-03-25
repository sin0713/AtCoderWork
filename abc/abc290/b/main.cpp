#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, k;
  string s;
  cin >> n >> k;
  cin >> s;

  int cnt = 0;
  rep(i, n) {
    if (s[i] == 'o') {
      cnt++;
      if (cnt > k) {
        s[i] = 'x';
      }
    }
  }

  rep(i, n) cout << s[i];
  cout << endl;
  return 0;
}