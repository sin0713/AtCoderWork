#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string S;
  cin >> S;

  int ans = 0;
  for (char c : S) {
    if (c == '+') {
      ans++;
      continue;
    }

    ans--;
  }

  cout << ans << endl;
  return 0;
}