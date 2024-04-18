#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int a, b;
  cin >> a >> b;
  int wa = a + b;  
  for (int i = 0; i < 10; i++) {
    if (i != wa) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}