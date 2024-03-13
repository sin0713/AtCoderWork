#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n = 64;
  ull sum = 0;
  rep(i, n) {
    ull a;
    cin >> a;

    sum += (a << i);
  }

  cout << sum << endl;
  return 0;
}