#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = unsigned long long;
using P = pair<int, int>;
const ll number = 998244353;

using mint = modint998244353;

int main() {
  int q;
  cin >> q;

  deque<int> dq;
  dq.push_back(1);
  mint ans = 1;

  rep(i, q) {
    int num;
    cin >> num;

    if (num == 1) {
      int x;
      cin >> x;
      dq.push_back(x);
      ans = ans * 10 + x;
    } else if (num == 2) {
      int x = dq.front(); dq.pop_front();
      ans -= x * mint(10).pow(dq.size());
    } else {
      cout << ans.val() << '\n';
    }
  }

  return 0;
}