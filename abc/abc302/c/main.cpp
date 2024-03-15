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
  rep(i, n) cin >> s[i];

  vector<int> order(n);
  rep(i, n) order[i] = i;

  do {
    bool allok = true;
    rep(i, n-1) {
      int cnt = 0;
      bool ok = true;
      rep(j, m) {
        if (s[order[i]][j] != s[order[i+1]][j]) cnt++;

        if (cnt > 1) {
          ok = false;
          break;
        }
      }

      if (!ok) {
        allok = false;
        break;
      }
    }
    if (allok) {
      cout << "Yes" << endl;
      return 0;
    }
  } while(next_permutation(order.begin(), order.end()));

  cout << "No" << endl;
  return 0;
}