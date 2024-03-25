#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// # A^2 <= x

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

// ll f(int x) {
//   ll res = 0;
//   for (int i = 1; i*i <= x; i++) {
//     if (x % i != 0) continue;

//     int j = x / i; 
//     if (i == j) res++;
//     else res += 2;
//   }

//   return res;
// }

int main() {
  int n;
  cin >> n;

  vector<ll> f(n+1);
  for (int a = 1; a < n; a++) {
    for (int b = 1; a*b < n; b++) {
      f[a*b]++;
    }
  }


  ll ans = 0;
  for (int x = 1; x < n; x++) {
    int y = n - x;
    ans += f[x] * f[y];
  }

  cout << ans << endl;
  return 0;
}