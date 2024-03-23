#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

const string piano = "wbwbwwbwbwbw";
int main() {
  int w, b;
  cin >> w >> b;

  int n = w+b;
  int m = piano.size();

  rep(i, m) {
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if (piano[(i+j) % m] == 'w') cnt++;
    }
    if (cnt == w) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}