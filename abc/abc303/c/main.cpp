#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

struct Point
{
  int x, y;

  Point(){};
  Point(int x_, int y_) : x(x_), y(y_){};
};

const vector<int> dx = {0, 1, 0, -1};
const vector<int> dy = {-1, 0, 1, 0};

int main() {
  int n, m, h, k;
  cin >> n >> m >> h >> k;

  string s;
  cin >> s;

  map<P, int> h_map;
  rep(i, m) {
    int x, y;
    cin >> x >> y;
    h_map[{x, y}]++;
  }

  Point current = Point(0, 0);
  map<char, int> d_mp({
      {'D', 0},
      {'R', 1},
      {'U', 2},
      {'L', 3},
  });
  rep(i, s.size()) {
    h--;
    if (h < 0) {
      cout << "No" << endl;
      return 0;
    }

    char c = s[i];
    current.x += dx[d_mp[c]];
    current.y += dy[d_mp[c]];
    if (h_map.count({current.x, current.y})) {
      if (h < k) {
        h_map.erase({current.x, current.y});
        h = k;
      }
    }
  }

  cout << "Yes" << endl;
  return 0;
}