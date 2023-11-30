#include <vector>
#include <algorithm>
#include <iostream>
#include <atcoder/all>
#include <math.h>
#include <numeric>
#include <iomanip>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF (1 << 30)

int main() {
  vector<int> cells(9);
  rep(i, 9) {
    cin >> cells[i];
  }

  vector<tuple<int, int, int>> row = {
    {0, 1, 2},
    {3, 4, 5},
    {6, 7, 8},
    {0, 3, 6},
    {1, 4, 7},
    {2, 5, 8},
    {0, 4, 8},
    {2, 4, 6}
  };
  vector<int> order(9); // i番目のマスが何番目に開けられるか
  iota(order.begin(), order.end(), 0);
  int all = 0;
  int not_disappointted_count = 0;

  do {
    all++;
    bool is_disappointted = false;
    for (auto &&[a, b, c] : row) {

      if (cells[a] == cells[b] && order[a] < order[c] && order[b] < order[c]) {
        is_disappointted = true;
      } else  if (cells[b] == cells[c] && order[b] < order[a] && order[c] < order[a]) {
        is_disappointted = true;
      }
      else if (cells[a] == cells[c] && order[a] < order[b] && order[c] < order[b]) {
        is_disappointted = true;
      }
    }
    if (!is_disappointted) not_disappointted_count++;
  } while(next_permutation(order.begin(), order.end())); // マスの開け方の全順列を試行する

  cout << setprecision(10);
  cout << (double)not_disappointted_count / all << endl;

  return 0;
}