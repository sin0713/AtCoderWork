#include <vector>
#include <algorithm>
#include <iostream>
#include <atcoder/all>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  bool isSame = true;
  int target = a[0];
  for (int i = 1; i < n; i++) {
    if (target == a[i]) continue; 

    isSame = false;
    break;
  }

  if (isSame) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}