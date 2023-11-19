#include <vector>
#include <algorithm>
#include <iostream>
#include <atcoder/all>
#include <set>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N; 
  string S;
  cin >> N >> S;

  vector<pair<char, int>> rle;
  rle.emplace_back(S[0], 0);
  for (char c : S) {
    if (c == rle.back().first) rle.back().second++;
    else rle.emplace_back(c, 1);
  }

  vector<int> mx(26);
  for (pair<char, int> pair : rle) {
    mx[pair.first - 'a'] = max(mx[pair.first - 'a'], pair.second);
  }

  int ans = 0;
  for (int num : mx) {
    ans += num;
  }

  cout << ans << endl;

  return 0;
}