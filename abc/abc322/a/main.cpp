#include <vector>
#include <algorithm>
#include <iostream>
#include <atcoder/all>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  string S;
  cin >> N >> S;

  int ans = -1;
  for(int i = 0; i < N - 2; i++) {
    if (S[i] == 'A' && S[i + 1] == 'B' && S[i + 2] == 'C') {
      ans = i;
      break;
    } 
  }

  if (ans == -1) {
    cout << ans << endl;
  } else {
    cout << ans + 1 << endl;
  }
  return 0;
}