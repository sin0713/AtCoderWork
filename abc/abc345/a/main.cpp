#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

bool solve() {
  string s;
  cin >> s;

  int n = s.size();
  if (s[0] != '<' || s[n-1] != '>') {
    return false;
  }

  for (int i = 1; i < n-1; i++) {
    if (s[i] != '=') {
      return false;
    }
  }

  return true;
}

int main() {
  if (solve()) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}