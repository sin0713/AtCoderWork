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
  int m;
  vector<string> s(3);
  cin >> m;
  rep(i, 3) cin >> s[i];

  int result = INF;
  for (int i = 0; i < 3*m; i++) {
    for (int j = 0; j < 3*m; j++) {
      for (int k = 0; k < 3*m; k++) {
        if (i == j || j == k || i == k) {
          continue;
        }

        char first = s[0][i % m];
        char second = s[1][j % m];
        char third = s[2][k % m];

        if (first == second && second == third) {
          result = min(result, max(i, max(j, k)));
        }
      }
    }
  }

  if (result < INF) {
    cout << result << endl;
  } else {
    cout << -1 << endl;
  }

  return 0;
}