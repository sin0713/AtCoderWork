#include <vector>
#include <algorithm>
#include <iostream>
#include <atcoder/all>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  int M;
  string S;
  string T;
  cin >> N >> M >> S >> T;

  // 接頭辞
  int prefix = true;
  rep(i, N) {
    if (S[i] != T[i]) {
      prefix = false;
      break;
    }
  }

  // 接尾辞
  int suffix = true;
  rep(i, N) {
    int s_index = N - (i + 1);
    int m_index = M - (i + 1);
    if (S[s_index] != T[m_index]) {
      suffix = false;
      break;
    };
  }

  if (suffix && prefix) {
    cout << 0 << endl;
  } else if (prefix) {
    cout << 1 << endl;
  } else if (suffix) {
    cout << 2 << endl;
  } else {
    cout << 3 << endl;
  }

  return 0;
}