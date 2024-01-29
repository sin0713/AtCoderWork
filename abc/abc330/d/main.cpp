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
  vector<string> s(n);

  rep(i, n) {
    cin >> s[i];
  }

  vector<long long> column(n, 0);
  vector<long long> row(n, 0);
  rep(i, n) {
    rep(j, n) {
      if (s[i][j] == 'o') {
        row[i]++;
        column[j]++;
      }
    }
  }

  long long res = 0;
  rep(i, n) {
    rep(j, n) {
      if (s[i][j] == 'o') {
        res += (row[i] - 1) * (column[j] - 1); 
      }
    }
  }
  
  cout << res << endl;

  return 0;
}