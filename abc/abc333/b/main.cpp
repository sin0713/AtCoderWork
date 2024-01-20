#include <vector>
#include <algorithm>
#include <iostream>
#include <atcoder/all>
#include <math.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF (1 << 30)

int main() {
  char a, b, c, d;
  cin >> a >> b >> c >> d;

  auto measure = [] (char x, char y) {
    int res = abs(x - y);
    if (res == 4 || res == 1) {
      return 1;
    } 

    return 2;
  };

  if (measure(a, b) == measure(c,d)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }





  return 0;
}