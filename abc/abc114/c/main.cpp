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

  int ans = 0;
  auto dfs = [&](auto dfs, ll cur, int used) {
    if (cur > n) return;
    if (used == 0b111) ans++;

    dfs(dfs, cur * 10 + 7, used | 0b001);
    dfs(dfs, cur * 10 + 5, used | 0b010);
    dfs(dfs, cur * 10 + 3, used | 0b100);
  };

  dfs(dfs, 0, 0);
  cout << ans << endl;
  return 0;
}