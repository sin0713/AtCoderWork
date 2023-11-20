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

  vector<int> a(n - 1);
  rep(i, n-1) cin >> a[i];

  // aを昇順に並べる
  // x = 10
  // 1 2 3 4 5 ?
  int max = 101;
  int ans = -1;
  rep(i, max) {
    vector<int> temp(a);
    temp.push_back(i);
    sort(temp.begin(), temp.end());

    int res = 0;
    for (int i = 1; i < (int)temp.size() - 1; i++) {
      res += temp[i];
    }

    if (res >= x) {
      ans = i;
      break;
    }
  }

  cout << ans << endl;

  return 0;
}