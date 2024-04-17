#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int M, D;
  cin >> M >> D;

  int y, m, d;
  cin >> y >> m >> d;

  if (m == M && d == D) {
    y++;
    m = 1;
    d =  1;
  } else if (d == D) {
    m++;
    d = 1;
  } else {
    d++;
  }
  printf("%d %d %d\n", y, m, d);
  return 0; 
}