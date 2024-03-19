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

  int ans = -1;
  auto f = [&] () {
    int cnt = 0;
    rep(i, n) {
      if(s[i] == 'o') cnt++;
      else {
        if (cnt == 0) continue;

        ans = max(ans, cnt);
        cnt = 0;
      }
    }
  };

  f();
  reverse(s.begin(), s.end());
  f();

  cout << ans << endl;
  return 0;
}