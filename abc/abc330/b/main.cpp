#include <vector>
#include <algorithm>
#include <iostream>
#include <atcoder/all>
#include <math.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  int l;
  int r;
  cin >> n >> l >> r;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  rep(i, n) {
    if (a[i] <= l) cout << l;
    else if (a[i] >= r) cout << r;
    else cout << a[i];
    cout << " ";
  }

  cout << endl;

  return 0;
}