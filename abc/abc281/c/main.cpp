#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n; 
  ll t;
  cin >> n >> t;

  vector<int> a(n);
  rep(i, n) cin >> a[i];

  vector<ll> d(n+1);
  d[0] = 0;
  rep(i, n) d[i+1] = d[i]+a[i];

  t %= d[n];

  int i = upper_bound(d.begin(), d.end(), t) - d.begin()-1;
  ll second = t-d[i];
  printf("%d %lld\n", i+1, second);
  return 0;
}