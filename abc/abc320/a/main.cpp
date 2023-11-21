#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <atcoder/all>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int a;
  int b;
  cin >> a >> b;
  long long res = pow(a, b) + pow(b, a);
  cout << res << endl;
  return 0;
}