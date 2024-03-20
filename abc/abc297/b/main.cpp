#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;

  int n = s.size();
  int b_sum = 0;
  int ki = s.find('K');
  vector<int> rs;
  rep(i, n) {
    if (s[i] == 'B') {
      b_sum += i;
    }
    if (s[i] == 'R') rs.push_back(i);
  }

  if (b_sum % 2 != 0 && ki > rs[0] && ki < rs[1]) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}