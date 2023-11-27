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
  int n;
  cin >> n;

  vector<int> result;
  rep(i, n+1) {
    int ans = 1000;
    for (int j = 1; j <= 9; j++) {
      if (n % j == 0 && i % (n / j) == 0) {
        ans = min(ans, j);
      }
    }

    result.push_back(ans);
  }

  for (int c : result) {
    if (c == 1000) {
      cout << "-";
    } else {
      cout << c;
    }
  }
  cout << endl;

  return 0;
}