#include <vector>
#include <algorithm>
#include <iostream>
// #include <atcoder/all>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  vector<int> d_list(n);
  rep(i, n) cin >> d_list[i];

  int ans = 0;
  // i + 1 = 月
  rep(i, n) {
    int month = i + 1;
    // j は日付
    if (month >= 10) {
      int res = month % 11;
      if (res != 0) continue;
      month /= 11;
    }

    rep(j, d_list[i]) {
      int day = j + 1;
      int a = day / 11;
      int b = day % 11;
      if (day == month || (a == month && b == 0)) {
        ans++;
      }
    }
  }

  cout << ans << endl;

  return 0;
}