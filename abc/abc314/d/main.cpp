#include <vector>
#include <algorithm>
#include <iostream>
#include <atcoder/all>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e18
using ll = long long;

int main() {
  int n, q;
  string s;
  cin >> n >> s >> q;

  vector<int> char_update_time(n);
  int lt = -1;
  int type = 2;
  rep(i, q) {
    int t, x; char c;
    cin >> t >> x >> c;
    x--;

    switch (t) {
      case 1:
        s[x] = c;
        char_update_time[x] = i;
        break;
      case 2:
        type = t;
        lt = i;
        break;
      case 3:
        type = t;
        lt = i;
        break;
      default:
        break;
    }
  }

  rep(i, n) {
    if (char_update_time[i] > lt) continue;

    if (type == 2) s[i] = tolower(s[i]); else s[i] = toupper(s[i]);
  }

  cout << s << endl;
  return 0;
}