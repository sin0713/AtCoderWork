#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int h, w;
  cin >> h >> w;

  vector<string> s(h);
  rep(i, h) cin >> s[i]; 

  rep(i, h) {
    for (int j = 0; j < w-1; j++) {
      if (s[i][j] == 'T' && s[i][j+1] == 'T') {
        s[i][j] = 'P';
        s[i][j+1] = 'C';
      }
    }
  }

  rep(i, h) cout << s[i] << '\n';
  return 0;
}