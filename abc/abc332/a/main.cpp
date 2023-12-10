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
  int n, s, k;
  cin >> n >> s >> k;

  vector<pair<int, int>> pq(n);
  rep(i, n) {
    int p;
    int q;
    cin >> p >> q;
    pair<int, int> pa = {p, q};
    pq[i] = pa;
  }

  int total = 0;
  for (pair<int, int> &p : pq) {
    int res = p.first * p.second;
    total += res;
  }

  if (total >= s) {
    cout << total << endl;
  } else {
    cout << total + k << endl;
  }

  return 0;
}