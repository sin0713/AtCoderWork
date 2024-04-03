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

  ll ans = 0;
  for (int i = 0; i < n; ) {
    ans++;
    if (s[i] == '0' && i+1 < n && s[i+1] == '0') { i += 2; } 
    else { i++; }
  }

  cout << ans << endl;
  return 0;
}