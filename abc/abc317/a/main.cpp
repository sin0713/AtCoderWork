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
  int h;
  int x;
  cin >> n >> h >> x;

  vector<int> p(n);
  rep(i, n) cin >> p[i];

  rep(i, n) {
    int res = h + p[i];
    if (res >= x) {
      cout << i + 1 << endl; 
      break;
    }
  }

  return 0;
}