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
  vector<pair<int, int>> flavors(n);
  rep(i, n) {
    int f;
    int s;
    cin >> f >> s;
    flavors.push_back({f, s});
  }

  auto cmp = [](pair<int, int> &a, pair<int, int> &b) -> bool {
    return a.second > b.second;
  };

  sort(flavors.begin(), flavors.end(), cmp);

 int result = 0;
  for (int i = 1; i < n; i++) {
    if (flavors[0].first != flavors[i].first) {
      result = max(result, (flavors[0].second + flavors[i].second));
    } else {
      result = max(result, (flavors[0].second + flavors[i].second / 2));
    } 
  }

  cout << result << endl;


  return 0;
}