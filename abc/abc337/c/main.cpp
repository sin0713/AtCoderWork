#include <vector>
#include <algorithm>
#include <iostream>
#include <atcoder/all>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e18
using ll = long long;

int main() {
  int n;
  cin >> n;

  vector<int> b(n, n);
  int front = 0;
  rep(i, n) {
    int a;
    cin >> a;
    a--;
    if (a < 0) {
      front = i;
      continue;
    }

    b[a] = i;
  }

  while(front < n) {
    cout << front + 1 << " ";
    front = b[front];
  }
  cout << endl;
  return 0;
}