#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, h, w;
  cin >> n >> h >> w;

  vector<P> ab(n);
  rep(i, n) cin >> ab[i].first >> ab[i].second;

  auto dfs = [&] (
    auto dfs, 
    vector<string> board,  
    vector<bool> used
  ) -> bool {
    int si = -1; int sj = -1; 
    rep(i, h) rep(j, w) {
      if (board[i][j] == '.' && si == -1) {
        si = i; sj = j;
      }
    }

    if (si == -1) {
      cout << "Yes" << endl;
      return true;
    }

    rep(ti, n) { // タイル
      if (used[ti]) continue;

      auto [a, b] = ab[ti];
      rep(ri, 2) { // 回転
        swap(a, b);
        if (si + a > h || sj + b > w) continue;

        vector<string> ns = board;
        bool ok = true;
        // タイル配置
        rep(ai, a) {
          rep(bi, b) {
            if (ns[si+ai][sj+bi] != '.') ok = false;

            ns[si+ai][sj+bi] = '1'+ti;
          }
        }
        if (!ok) continue; 

        used[ti] = true;
        if (dfs(dfs, ns, used)) return true;
        used[ti] = false;
      }
    }

    return false;
  };

  
  if (!dfs(dfs, vector<string>(h, string(w, '.')), vector<bool>(n))) {
    cout << "No" << endl;
  }
  return 0;
}