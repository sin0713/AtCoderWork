#include <vector>
#include <algorithm>
#include <iostream>
#include <atcoder/all>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  int l;
  cin >> n >> l;

  vector<int> a(n);
  rep(i, n) cin >> a[i];

  int ans = 0;
  rep(i, n) {
    if (a[i] >= l) {
      ans++;
    }
  }
   
 cout << ans << endl;

  return 0;
}