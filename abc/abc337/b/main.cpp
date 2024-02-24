#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e18
using ll = long long;

int main() {
  string s;
  cin >> s;

  int a = ranges::count(s, 'A');
  int b = ranges::count(s, 'B');
  int c = ranges::count(s, 'C');

  if (s == string(a, 'A') + string(b, 'B') + string(c, 'C')) {
    cout << "Yes" << endl;
    return 0;
  }

  cout << "No" << endl;

  return 0;
}