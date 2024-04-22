#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, q;
  cin >> n >> q;
  vector<bool> tooth(n, true);
  rep(i, q) {
    int t;
    cin >> t;
    t--;

    if (tooth[t]) tooth[t] = false;
    else tooth[t] = true;
  }

  int ans = 0;
  rep(i, n) {
    if (tooth[i]) ans++;
  }

  cout << ans << endl;
  return 0;
}