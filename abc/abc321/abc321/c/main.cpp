#include <vector>
#include <algorithm>
#include <iostream>
#include <atcoder/all>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  long long k;
  cin >> k;

  vector<long long> result;
  for (int i = 2; i < (1<<10); i++) {
    long long num = 0;
    for (int j = 9; j >= 0; j--) {
      if (i & (1 << j)) {
        num = num*10 + j;
      }
    }
    if (num > 0) result.emplace_back(num);
  }

  sort(result.begin(), result.end());
  cout << result[k-1] << endl;

  return 0;
}