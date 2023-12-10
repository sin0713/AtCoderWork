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
  int n, m;
  string s;
  cin >> n >> m >> s;

  int current_plain_shirt = m;
  int current_logo_shirt = 0;
  int neccesary_logo_shirt = 0;
  for (char &c : s) {
    if (c == '0') {
      current_plain_shirt = m;
      current_logo_shirt = neccesary_logo_shirt;
    } else if (c == '1') {
      if (current_plain_shirt != 0) {
        current_plain_shirt--;
      } else {
        if (current_logo_shirt == 0) {
          neccesary_logo_shirt++;
          continue;
        }
        current_logo_shirt--;
      }
    } else if (c == '2') {
        if (current_logo_shirt == 0) {
          neccesary_logo_shirt++;
          continue;
        }
        current_logo_shirt--;
    }
  }

  cout << neccesary_logo_shirt << endl;

  return 0;
}