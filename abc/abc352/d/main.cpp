#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> p(n);
  rep(i, n) {
    cin >> p[i];
    p[i]--;
  }

  vector<int> q(n);
  rep(i, n) q[p[i]] = i;

  int ans = n;
  set<int> st;
  rep(i, n) {
    st.insert(q[i]);

    if (st.size() > k) {
      st.erase(q[i-k]);
    }

    if (st.size() == k) {
      int now = *st.rbegin() - *st.begin();
      ans = min(ans, now);
    }
  }

  cout << ans << endl;
  return 0;
}