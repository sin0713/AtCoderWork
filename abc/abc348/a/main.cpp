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

  rep(i, n) {
    if ((i+1)%3 == 0) {
      cout << 'x';
    } else {
      cout << 'o';
    }
  }
  cout << endl;
  return 0;
}