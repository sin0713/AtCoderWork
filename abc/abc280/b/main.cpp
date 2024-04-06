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
  vector<int> s(n+1);
  s[0] = 0;
  rep(i, n) cin >> s[i+1];

  rep(i, n) {
    int ans = s[i+1] - s[i];
    cout << ans << " ";
  }
  cout << endl;
  return 0;
}