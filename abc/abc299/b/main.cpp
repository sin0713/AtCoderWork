#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

void chmax(P& a, P b) {
  if (a.second < b.second) a = b;
}

int main()
{
  int n, t;
  cin >> n >> t;

  vector<int> c(n);
  vector<int> r(n);
  rep(i, n) cin >> c[i];
  rep(i, n) cin >> r[i];

  P t_player = {-1, -1};
  P first_player = {0, r[0]};
  int first_color = c[0];

  rep(i, n) {
    P player = {i, r[i]};

    if (c[i] == t) {
      chmax(t_player, player);
    } else if (c[i] == first_color) {
      chmax(first_player, player);
    }
  }
  
  int ans = -1;
  if (t_player.first == -1) ans = first_player.first + 1; 
  else ans = t_player.first + 1;

  cout << ans << endl;
  return 0;
}