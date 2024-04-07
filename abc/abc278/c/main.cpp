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

  map<int, set<int>> mp;

  rep(i, q) {
    int t, a, b;
    cin >> t >> a >> b;
    a--; b--;
    if (t == 1) {
      mp[a].insert(b);
    } else if (t == 2) {
      if (mp.count(a) && mp[a].count(b)) {
        mp[a].erase(b);
      }
    } else {
      if (mp.count(a) 
        && mp.count(b) 
        && mp[a].count(b) 
        && mp[b].count(a)
      ) {
        cout << "Yes" << '\n';
      } else {
        cout << "No" << '\n';
      }
    }
  }
  return 0;
}

