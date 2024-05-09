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
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  rep(ki, k) {
    vector<int> b;
    for (int ai = ki; ai < n; ai+=k) {
      b.push_back(a[ai]);
    }
    sort(b.begin(), b.end());
    for (int ai = ki; ai < n; ai+=k) {
      a[ai] = b[ai/k];
    }
  }

  vector<int> temp = a;
  sort(temp.begin(), temp.end());
  if (temp == a) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}