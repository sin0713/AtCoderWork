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
  vector<int> a(n-1);
  rep(i, n-1) cin >> a[i];

  int sum = 0;
  rep(i, n-1) sum += a[i];

  if (sum == 0) cout << sum << endl;
  else if (sum < 0) cout << abs(sum) << endl;
  else cout << -sum << endl;
  return 0;
}