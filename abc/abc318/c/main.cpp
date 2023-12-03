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
  int d;
  long long p;
  cin >> n >> d >> p;
  
  vector<int> f(n);
  rep(i, n) cin >> f[i];
  sort(f.rbegin(), f.rend());

  int set_count = 0;
  long long normal_total = 0;
  long long result = 0;
  for (int i = 0; i < n; i++) {
    if (set_count == d) {
      long long res = min(p, normal_total);
      result += res;

      normal_total = 0;
      set_count = 0;
    }

    normal_total += f[i];
    set_count++;
  }

  if (normal_total != 0) {
    long long res = min(normal_total, p);
    result += res;
  }

  cout << result << endl;

  return 0;
}