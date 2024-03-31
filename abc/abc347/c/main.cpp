#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n, a, b;
  cin >> n >> a >> b;

  ll w = a+b;
  vector<ll> d(n);
  rep(i, n) { 
    ll x;
    cin >> x;

    x %= w;
    d[i] = x;
  }

  sort(d.begin(), d.end());
  rep(i, n) d.push_back(d[i]+w);

  rep(i, n) {
    int l = d[i]; int r = d[i+n-1];
    if (r-l+1 <= a) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;

  return 0;
}