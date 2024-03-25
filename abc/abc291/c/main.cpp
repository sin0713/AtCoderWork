#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

map<char, P> direc = {
    {'R', pair(1, 0)},
    {'L', pair(-1, 0)},
    {'U', pair(0, 1)},
    {'D', pair(0, -1)}
};

int main() {
  int n;
  string s;
  cin >> n >> s;

  set<P> st;
  int x = 0;
  int y = 0;
  st.insert(pair(x, y));
  rep(i, n) {
    auto [move_x, move_y] = direc[s[i]];
    x += move_x;
    y += move_y;

    auto n_posi = pair(x, y);
    if (st.count(n_posi)) {
      cout << "Yes" << endl;
      return 0;
    }
    st.insert(n_posi);
  }

  cout << "No" << endl;
  return 0;
}