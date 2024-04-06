#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  string s;
  cin >> s;
  n = s.size();
  int m = 26;
  const char a = 'A';
  const char zero = '0';

  auto isOk = [&]() -> bool {
    if (n != 8) return false;

    int front = s[0]-a;  
    int back = s[n-1]-a;
    if (front < 0 || back < 0 || front >= m || back >= m) {
      return false;
    } 

    for (int i = 1; i < n-1; i++) {
      if (i == 1 && s[i] == zero) {
        return false;
      }

      int middle = s[i] - zero; 
      if (middle > 9) return false;
    }

    return true;
  };

  if (isOk()) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}