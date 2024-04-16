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
  ll p, q, r;
  cin >> p >> q >> r;

  vector<int> a(n);
  rep(i, n) cin >> a[i];

  vector<ll> sums(n+1);
  rep(i, n) {
    sums[i+1] = sums[i] + a[i];
  }

  set<ll> st;
  rep(i, n+1) st.insert(sums[i]);

  rep(xi, n+1) {
    ll sum_y = sums[xi] + p;  
    ll sum_z = sum_y + q;
    ll sum_w = sum_z + r;
    if (st.count(sum_y) && st.count(sum_w) && st.count(sum_z)) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
  return 0;
}