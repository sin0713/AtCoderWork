#include <vector>
#include <algorithm>
#include <iostream>
#include <atcoder/all>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string n;
  cin >> n;

  bool ans = true;
  rep(i, (int)(n.size() - 1)) {
    int target = n[i];
    int target_next = n[i + 1];
    if (target > target_next) continue;

    ans = false;
    break;
  }

  if (ans) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}