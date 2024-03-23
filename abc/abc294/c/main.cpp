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

  vector<int> a(n);
  vector<int> b(m);
  rep(i, n) cin >> a[i];
  rep(i, m) cin >> b[i];

  vector<int> c(a);
  c.insert(c.end(), b.begin(), b.end());
  sort(c.begin(), c.end());

  rep(i, n) {
    int index = lower_bound(c.begin(), c.end(), a[i]) - c.begin();
    cout << index + 1 << " ";
  }
  cout << endl;
  rep(i, m) {
    int index = lower_bound(c.begin(), c.end(), b[i]) - c.begin();
    cout << index + 1 << " ";
  }
  cout << endl;
  return 0;
}