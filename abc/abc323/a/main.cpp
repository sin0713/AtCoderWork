#include <vector>
#include <algorithm>
#include <iostream>
#include <atcoder/all>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string S;
  cin >> S;

  bool ans = true;
  rep(i, S.size()) {
    if (i % 2 == 1) {
      if (S[i] != '0') {
        ans = false;
        break;
      }
    }
  }

  if (ans) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}