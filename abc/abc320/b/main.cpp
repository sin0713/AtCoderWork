#include <vector>
#include <algorithm>
#include <iostream>
#include <atcoder/all>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string s;
  cin >> s;

  int ans = 1;
  for (int i = 0; i < (int)s.size()-1; i++) {
    for(int j = i + 1; j < (int)s.size(); j++) {
      string str = "";
      for(int k = i; k <= j; k++) str += s[k];

      string temp = str;
      reverse(str.begin(), str.end());
      if (str == temp) {
        ans = max(ans, (int)temp.size());
      }
    }
  }

  cout << ans << endl;

  return 0;
}