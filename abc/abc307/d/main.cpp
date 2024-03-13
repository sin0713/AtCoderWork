#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  string s;
  cin >> n >> s;

  vector<string> st;
  st.push_back("");
  rep(i, n) {
    if (s[i] == '(') {
      st.push_back("(");
    } else if (s[i] == ')') {
      if (st.size() == 1) st.back() += s[i];
      else st.pop_back();
    } else {
      st.back() += s[i];
    }
  }

  rep(i, st.size()) {
    rep(j, st[i].size()) cout << st[i][j];
  }
  cout << endl;
  return 0;
}