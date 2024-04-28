#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, k, q;
  cin >> n >> k >> q;
  vector<bool> table(n);
  rep(i, k) {
    int a;
    cin >> a;
    a--;
    table[a] = true;
  }

  rep(qi, q) {
    int l;
    cin >> l;

    int cnt = 0;
    rep(ni, n) {
      if (!table[ni]) continue;

      cnt++;
      if (cnt == l) {
        if (ni == n-1 || table[ni+1]) break;

        swap(table[ni], table[ni+1]);
        break;
      }
    }
  }

  rep(i, n) {
    if (table[i]) {
      cout << i+1 << " ";
    }
  }
  cout << endl;
  return 0;
}