#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;

  int p = 0;
  rep(i, q) {
    int t,x;
    cin >> t >> x;

    if (t == 1) {
      p = (p-x+n) % n;
      continue;
    }

    cout << s[(p+x-1)%n] << '\n';
  } 
  return 0;
}