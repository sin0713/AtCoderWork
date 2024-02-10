#include <vector>
#include <algorithm>
#include <iostream>
#include <atcoder/all>
#include <math.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF (1 << 30)

int main() {
  string s;
  cin >> s;

  string res;
  rep(i, (int)s.size()) {
    res.push_back(s[i]);

    if (!res.empty() && res.size() >= 3) {
      int start_index = res.size() - 3;
      if (res.substr(start_index) == "ABC") {
        res.erase(start_index);
      }
    }
  }

  cout << res << endl;
  return 0;
}