#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int ah, aw;
  cin >> ah >> aw;
  vector<vector<int>> a(ah, vector<int>(aw));
  rep(i, ah) rep(j, aw) cin >> a[i][j];

  int bh, bw;
  cin >> bh >> bw;
  vector<vector<int>> b(bh, vector<int>(bw));
  rep(i, bh) rep(j, bw) cin >> b[i][j];


  for (int bith = 1; bith < (1<<ah); bith++) {
    for (int bitw = 1; bitw < (1<<aw); bitw++) {
      vector<int> hi_list, wi_list;
      rep(i, ah) if (bith & (1<<i)) hi_list.push_back(i);
      rep(i, aw) if (bitw & (1<<i)) wi_list.push_back(i);

      if (hi_list.size() != bh) continue;
      if (wi_list.size() != bw) continue;

      vector c(bh, vector<int>(bw));
      rep(i, bh) {
        rep(j, bw) {
          c[i][j] = a[hi_list[i]][wi_list[j]];
        }
      }
      if (c == b) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;
  return 0;
}