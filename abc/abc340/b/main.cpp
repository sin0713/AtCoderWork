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
  cin >> n;

  vector<int> list;
  rep(i, n) {
    int first;
    int second;
    cin >> first >> second;

    if (first == 1) {
      list.push_back(second);
      continue;
    }

    cout << list[list.size() - second] << endl;
  }
  return 0;
}