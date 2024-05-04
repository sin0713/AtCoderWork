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

  vector<int> ans;
  int index = 0;
  for (char c : s) {
    while(index < t.size() && t[index] != c) index++;

    ans.push_back(index+1);
    index++;
  }

  for (int x : ans) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}