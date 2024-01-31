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
  cin >> n >> m;

  vector<int> a(n);
  int winner_position = 0;
  rep(i, m) {
    int target;
    cin >> target;

    int position = target - 1;
    a[position]++;
    if (a[winner_position] < a[position]) {
      winner_position = position;
    } else if (a[winner_position] == a[position] && winner_position > position) {
      winner_position = position;
    }

    cout << winner_position + 1 << endl;
  }

  return 0;
}