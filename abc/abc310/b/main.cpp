#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, unordered_map<int, int>>;

int main()
{
  int n, m;
  cin >> n >> m;

  vector<int> p(n);
  vector<vector<int>> f(n);

  rep(i, n) {
    int price, c;
    cin >> price >> c;

    p[i] = price;
    f[i] = vector<int>(c);
    rep(j, c) {
      cin >> f[i][j];
    }
  }

  rep(i, n) {
    rep(j, n) {
      if (i == j) continue;
      if (p[i] < p[j]) continue;

      int li = f[i].size();
      int lj = f[j].size();
      bool ok = true;
      rep(k, li) {
        bool flag = false;
        rep(h, lj) {
          if (f[i][k] == f[j][h]) { flag = true; } 
        }
        // 見つからなかったら
        if (!flag) { ok = false; break; }
      }

      if (!ok) continue;

      if(p[i] == p[j] && f[i] == f[j]) continue;

      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
  return 0;
}