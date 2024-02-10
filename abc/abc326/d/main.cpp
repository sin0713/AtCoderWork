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
  int n; 
  string r, c;
  cin >> n >> r >> c;

  auto f = [&] (auto f, char x, vector<string> s) -> bool {
    if (x == 'D') {
      string resC = "";
      string resR = "";

      rep(i, n) {
        rep(j, n) {
          if (s[i][j] != '.') {
            resR += s[i][j];
            break;
          }
        }
      }
      rep(i, n) {
        rep(j, n) {
          if (s[j][i] != '.') {
            resC += s[j][i];
            break;
          }
        }
      }

      if (resC == c && resR == r) {
        cout << "Yes" << endl;
        rep(i, n) {
          cout << s[i] << endl;
        }
        return true;
      } 

      return false;
    }

    vector<int> p(n);
    rep(i, n) p[i] = i;

    do { 
      auto t = s;
      bool ok = true;
      rep(i, n) { 
        if (t[i][p[i]] != '.') ok = false;
        t[i][p[i]] = x; 
      }

      if (!ok) continue;
      if (f(f, x+1, t)) return true;
    } while(next_permutation(p.begin(), p.end()));

    return false;
  };

  vector<string> table(n, string(n, '.'));
  if (!f(f, 'A', table)) cout << "No" << endl;
  
  return 0;
}