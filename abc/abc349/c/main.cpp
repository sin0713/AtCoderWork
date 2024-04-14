#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  string s, t;
  cin >> s >> t;

  int ts = 3;
  const int ss = s.size();

  vector<int> tnums(ts);
  rep(i, ts) {
    tnums[i] = t[i] - 'A';
  }

  int t_itr = 0;
  if (t[ts-1] == 'X') { ts--; }
  rep(i, ss) {
    int res = s[i] - 'a';
    if (res == tnums[t_itr]) {
      t_itr++;
      if (t_itr == ts) break;
    }
  }

  if(t_itr == ts) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}