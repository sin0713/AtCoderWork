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
  rep(i, n) {
    cin >> a[i];
  }

  const int M = 1000005;
  vector<vector<int>> is(M); 
  rep(i, n) {
    is[a[i]].push_back(i);
  }

  vector<long long> ans(n);
  long long sum = 0;
  for (int value = M; value >= 1; value--) {
    for (int x : is[value]) {
      ans[x] = sum;
    }
    sum += (long long)value * is[value].size();
  }

  rep(i, n) {
    cout << ans[i] << " ";
  }
  cout << endl;

  return 0;
}