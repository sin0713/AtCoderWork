#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m, l;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  cin >> m;
  vector<int> b(m);
  rep(i, m) cin >> b[i];

  cin >> l;
  vector<int> c(l);
  rep(i, l) cin >> c[i];

  int q;
  cin >> q;
  vector<ll> x(q);
  rep(i, q) cin >> x[i];

  unordered_map<ll, int> d;
  rep(i, n) {
    rep(j, m) {
      rep(k, l) {
        ll sum = a[i]+b[j]+c[k];
        d[sum]++;
      }
    }
  }

  rep(i, q) {
    if (d[x[i]]>0) cout << "Yes" << '\n';
    else cout << "No" << '\n';
  }

  return 0;
}