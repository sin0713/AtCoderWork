#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  string s;
  cin >> n >> s;

  for (int i = 1; i < n; i++) {
    int ans = 0;
    for (int j = 0; j< n-1; j++) {
      if (j+i >= n) break; 

      if (s[j] == s[j+i]) {
        break;
      };

      ans = j+1;
    }
    cout << ans << '\n';
  }
  return 0;
}