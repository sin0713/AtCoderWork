#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  string s;
  cin >> n >> s;

  bool in_quote = false;
  rep(i, n) {
    if (s[i] == '\"') {
      in_quote = !in_quote;
    } else if (s[i] == ',' && !in_quote) {
      s[i] = '.';
    }
  }

  cout << s << endl;
  return 0;
}