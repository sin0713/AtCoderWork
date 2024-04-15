#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

const ll mod = 998244353;

int main() {
  ll n; 
  cin >> n;

  n %= mod;
  if (n < 0) cout << (n + mod) % mod << endl;
  else cout << n << endl;
  return 0;
}