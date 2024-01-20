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
  int n, s, m, l;
  cin >> n >> s >> m >> l;



  int res = INF;
  rep(i, INF) {
    int total_num_s = 6 * i;
    int total_money_s = s * i; 
    if (total_num_s >= n) {
      res = min(total_money_s, res);
      break;
    }
    rep(j, INF) {
      int total_num_m = 8 * j;
      int total_money_m = m * j;
      if (total_num_s + total_num_m >= n) {
        res = min(total_money_s + total_money_m, res);
        break;
      }
      rep(k, INF) {
        int total_num_l = 12 * k; 
        int total_money_l = l * k;
        if (total_num_s + total_num_m + total_num_l >= n) {
          res = min(total_money_s + total_money_m + total_money_l, res);
          break;
        }
      }
    }
  }

  cout << res << endl;

  return 0;
}