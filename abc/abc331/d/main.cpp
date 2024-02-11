#include <vector>
#include <algorithm>
#include <iostream>
#include <atcoder/all>
#include <math.h>
#include <bitset>

using namespace std;
using ll = long long; 

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF (1 << 30)

int main() {
  int n, q;
  cin >> n >> q;

  vector<string> a(n);
  rep(i, n) {
    rep(j, n) {
      cin >> a[i][j];
    }
  }

  // 累積和管理配列作成
  vector<vector<long long>> s(n+1, vector<long long>(n+1, 0));
  rep(i, n) {
    rep(j, n) {
      s[i+1][j+1] = (ll)s[i][j+1] + (ll)s[i+1][j] - (ll)s[i][j] + (ll)(a[i][j] == 'B');
    }
  }

  // black 計測関数
  auto get_black_num = [&] (int x, int y) {
    long long res = 0;

    ll x_size = x / n;
    ll y_size = y / n;
    ll remaining_x = x % n;
    ll remaining_y = y % n;

    long long all_num = s[n][n];
    res += all_num * x_size * y_size;

    long long bottom_num = s[remaining_y][n];
    res += bottom_num * x_size;

    long long right_side_num = s[n][remaining_x];
    res += right_side_num * y_size;

    long long remaining_num = s[remaining_y][remaining_x];
    res += remaining_num;

    return (ll)res;
  };

  vector<ll> ans_list;
  rep(i, q) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    ++c;
    ++d;

    long long ans = get_black_num(d, c) - get_black_num(d, a) - get_black_num(b, c) + get_black_num(b, a);
    ans_list.push_back(ans);
  }

  rep(i, (int)ans_list.size()) {
    cout << ans_list[i] << endl;
  }

  return 0;
}