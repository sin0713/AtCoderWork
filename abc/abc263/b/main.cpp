#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 1; i < n; i++) {
    int x;
    cin >> x;
    x--;
    p[i] = x;
  }

  int ans = 0;
  int current = n-1;
  while(current != 0) {
    current = p[current];
    ans++;
  }

  cout << ans << endl;
  return 0;
}