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
  int m;
  cin >> m;
  vector<int> d(m);
  rep(i, m) cin >> d[i];

  int total_day = 0;
  rep(i, m) {
    total_day += d[i];
  }
  
  int mid_day = (total_day + 1) / 2;

  int count_day = 0;
  rep(i, m) {
    if (mid_day <= d[i]) {

      cout << i+1 << " " << mid_day << endl; 
      break;
    } 

    mid_day -= d[i];
  }

  return 0;
}