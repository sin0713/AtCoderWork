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
  rep(i, (int)S.size()) {
    if (i == ((int)S.size() - 1)) {
      cout << S[i];
      break;
    }
    cout << S[i] << " ";
  }

  return 0;
}