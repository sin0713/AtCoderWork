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
  int h, w, n;
  cin >> h >> w >> n;

  pair<int, int> pos = {0, 0};
  int direction = 0;
  vector<string> s(h, string(w, '.'));

  auto move = [&] (int direction) {
    switch (direction) {
      case 0:
        pos.first--;
        break;
      case 1:
        pos.second++;
        break;
      case 2:
        pos.first++;
        break;
      case 3:
        pos.second--;
        break;
      default:
        break;
    }

    if (pos.first < 0) pos.first = h-1; else pos.first %= h;
    if (pos.second < 0) pos.second = w-1; else pos.second %= w;
  };

  rep(i, n) {
    if (s[pos.first][pos.second] == '.') { 
      direction++; 
      s[pos.first][pos.second] = '#';
    } else { 
      direction += 3; 
      s[pos.first][pos.second] = '.';
    }
    direction %= 4;
    move(direction);
  }

  rep(i, h) {
    cout << s[i] << endl;
  }
  return 0;
}