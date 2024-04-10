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
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  vector<int> secs, thirs;
  unordered_set<int> st;
  rep(i, n) {
    int sec_cnt = 0;
    while(a[i] % 2 == 0) {
      a[i] /= 2;
      sec_cnt++;
    }
    int thir_cnt = 0;
    while(a[i] % 3 == 0) {
      a[i] /= 3;
      thir_cnt++;
    }
    secs.push_back(sec_cnt);
    thirs.push_back(thir_cnt);
    st.insert(a[i]);
  }

  if (st.size() != 1) {
    cout << -1 << endl;
    return 0;
  }

  auto f = [&] (vector<int>& list) -> int {
    int m = 1001001001;
    rep(i, n) {
      m = min(m, list[i]);
    }

    int res = 0;
    rep(i, n) res += list[i]-m;
    return res;
  };

  int ans = f(secs) + f(thirs);
  cout << ans << endl;
  return 0;
}