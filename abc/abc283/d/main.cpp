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
      if (stack.size() == 1 && stack.back() == "") {
        string& bk = stack.back();
        bk.push_back(s[i]);
      } else {
        string str{s[i]}; 
        stack.push_back(str);
      }
    } else if (s[i] == ')') {
      string bk = stack.back(); 
      stack.pop_back();
      int m = bk.size();
      for (int j = m-1; j >= 1; j--) {
        st.erase(bk[j]);
      }
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