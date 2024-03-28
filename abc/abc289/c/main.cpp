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

  vector<vector<int>> c(m);
  rep(i, m) {
    int size;
    cin >> size;
    c[i].resize(size);
    rep(j, size) cin >> c[i][j];
  }

  int ans = 0;
  for (int bit = 1; bit < (1 << m); bit++) {
    unordered_set<int> st;

    rep(i, m) {
      if (bit & (1 << i)) {
        rep(j, c[i].size()) {
          st.insert(c[i][j]);
        }
      }
    }
    if (st.size() == n) ans++;
  }

  cout << ans << endl;
  return 0;
}