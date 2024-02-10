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
  string s;
  cin >> n >> s;

  vector<int> num_counter(10);
  for (char c : s) {
    num_counter[c - '0']++;
  }

  long long index = 0;
  int ans = 0;
  while(true) {
    string target = to_string(index*index);
    if (target.size() > s.size()) break;
    vector<int> target_num_counter(10);
    for (char c : target) target_num_counter[c - '0']++;
    target_num_counter[0] += (s.size() - target.size());
    if (target_num_counter == num_counter) ans++;
    index++;
  }

  cout << ans << endl;
  return 0;
}