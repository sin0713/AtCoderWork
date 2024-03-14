#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) { cin >> a[i]; }

  vector<int> d(n + 1);
  d[0] = 0;
  rep(i, n)
  {
    d[i + 1] = d[i];

    if (i % 2 == 0)
    {
      int sum = a[i] - a[i - 1];
      d[i + 1] += sum;
    }
  }

  auto f = [&](int value) -> int
  {
    int i = lower_bound(a.begin(), a.end(), value) - a.begin() - 1;
    if (i < 0)
      return 0;

    int result = d[i + 1];
    if (i % 2 == 1)
    {
      result += value - a[i];
    }
    return result;
  };

  int q;
  cin >> q;
  rep(i, q)
  {
    int left, right;
    cin >> left >> right;
    int ans = f(right) - f(left);
    cout << ans << '\n';
  }
  return 0;
}
