#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;

  int n = s.size();
  int cnt = 0;
  rep(i, n) {
    if (s[i] == '|') {
      cnt++;
      continue;
    }
    if (cnt == 1) continue;

    cout << s[i];
  }

  cout << endl;
  return 0;
}