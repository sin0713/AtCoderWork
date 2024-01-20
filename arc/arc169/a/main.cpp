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
  vector<int> a(n);
  vector<int> p(n - 1);
  rep(i, n) { cin >> a[i]; }
  rep(i, n - 1) { cin >> p[i]; }

  long long cnt = 0;
  while(cnt <= 1e100) {
    for (int i = 1; i < n; i++) {
      a[p[i - 1]] += a[i]; 
    }
  }

  if (a[0] < 0) {
    cout << "-" << endl;
  } else if (a[0] > 0) {
    cout << "+" << endl;
  } else {
    cout << 0 << endl;
  }



  return 0;
}