#include <vector>
#include <algorithm>
#include <iostream>
#include <atcoder/all>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  int x;
  cin >> n >> x;
  vector<int> point_list(n);
  rep (i, n) cin >> point_list[i];

  long long ans = 0;
  rep(i, n) {
    if(point_list[i] <= x) {
      ans += point_list[i];
    }
  }

  cout << ans << endl;

  return 0;
}