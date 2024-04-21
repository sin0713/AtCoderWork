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
  rep(i, n) {
    cin >> a[i]; 
    a[i]--;
  }

  ll same = 0;
  rep(i, n) {
    if (a[i] == i) same++;
  }
  ll ans = 0;
  ans += same * (same-1) / 2;

  rep(i, n) {
    if (a[i] <= i) continue;

    if (a[a[i]] == i) ans++;
  }

  cout << ans << endl;
  return 0;
}