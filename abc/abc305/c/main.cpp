#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int h, w;
  cin >> h >> w;

  vector<string> s(h);
  rep(i, h) cin >> s[i];

  vector<P> hp(h);
  vector<P> wp(w);

  rep(i, h) {
    int sum = 0;
    rep(j, w) {
      if (s[i][j] == '#') sum++;
    }
    hp[i] = {i, sum};
  }

  rep(j, w) {
    int sum = 0;
    rep(i, h) {
      if (s[i][j] == '#') sum++;
    }
    wp[j] = {j, sum};
  }

  int hmax = -1;
  int wmax = -1;
  rep(i, h) hmax = max(hmax, hp[i].second);
  rep(i, w) wmax = max(wmax, wp[i].second);

  vector<int> ans;
  rep(i, h) if (hp[i].second == hmax - 1) ans.push_back(hp[i].first);
  rep(i, w) if (wp[i].second == wmax - 1) ans.push_back(wp[i].first);

  cout << ans[0]+1 << " " << ans[1]+1 << endl;
  return 0;
}