#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  vector<ll> d; 
  while(true) {
    ll a;
    cin >> a;
    if (a == 0) {
      d.push_back(a);
      break;
    }

    d.push_back(a);
  }

  int n = d.size();
  reverse(d.begin(), d.end());
  rep(i, n) {
    cout << d[i] << '\n';
  }
  return 0; 
}