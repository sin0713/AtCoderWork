#include <vector>
#include <algorithm>
#include <iostream>
#include <atcoder/all>
#include <math.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int d;
  cin >> d;

  long long res = d;
  int x = 1;
  while(true) {
    int first_num = abs(pow(x, 2) + pow(1, 2) - d); 
    if (first_num > res) {
      break;
    }
    int y = 1;
    while(true) {
      int num = abs(pow(x, 2) + pow(y, 2) - d); 
      if (num < res) {
        res = num;
      } else {
        break;
      }
      y++;
    }
    x++;
  }









  return 0;
}