#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

bool solve() {
  unordered_set<char> fcs = {'H', 'D', 'C', 'S'};
  unordered_set<char> scs = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };

  int n;
  cin >> n;
  vector<string> s(n);
  rep(i, n) cin >> s[i];

  unordered_set<string> st;
  for (string& ss : s) {
    if (!fcs.count(ss[0]) || !scs.count(ss[1])) {
      return false;
    }

    if (st.count(ss)) {
      return false;
    }

    st.insert(ss);
  }

  return true;
}

int main() {
  if (solve()) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}