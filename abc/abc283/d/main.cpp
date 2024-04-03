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
  vector<string> stack;
  unordered_set<char> st;
  stack.push_back("");
  rep(i, n) {
    if (s[i] == '(') {
      stack.push_back("");
    } else if (s[i] == ')') {
      string bk = stack.back(); 
      for (char c : bk) {
        st.erase(c);
      }
      stack.pop_back();
    } else {
      if (st.count(s[i])) {
        cout << "No" << endl;
        return 0;
      }
      st.insert(s[i]);
      string& bk = stack.back();
      bk.push_back(s[i]);
    }
  }

  cout << "Yes" << endl;
  return 0;
}