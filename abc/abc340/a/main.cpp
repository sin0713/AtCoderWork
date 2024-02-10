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
  int s, e, diff;
  cin >> s >> e >> diff;

  while(true) {
    cout << s << " ";
    if (s == e) {
      break;
    }
    s += diff;
  }

  cout << endl;

  return 0;
}