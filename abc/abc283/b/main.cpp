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

  int q;
  cin >> q;
  rep(i, q) {
    int query, k;
    cin >> query >> k;
    k--;

    if (query == 1) {
      int  x;
      cin >> x;

      a[k] = x;
    } else {
      cout << a[k] << '\n';
    }
  }
  return 0;
}