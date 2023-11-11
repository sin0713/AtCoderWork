#include <vector>
#include <algorithm>
#include <iostream>
#include <atcoder/all>
#include <math.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

long long i = 1 << 10;

int main() {
  long long n;
  cin >> n;

  while(n % 2 == 0) n /= 2;
  while(n % 3 == 0) n /= 3;

  if (n == 1) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}