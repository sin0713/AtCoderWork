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

  const int m = 5;
  vector<int> x(m * n);
  rep(i, m * n) cin >> x[i];

  sort(x.begin(), x.end());

  long double sum = 0;
  rep(i, n*m) {
    if (i < n || i >= 4*n) continue;

    sum += x[i];
  }

  long double ans = sum / (long double)(3*n);
  cout << ans << endl;
  return 0;
}