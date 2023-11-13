#include <vector>
#include <algorithm>
#include <iostream>
// #include <atcoder/all>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  vector<string> S(N);
  rep(i, N)  cin >> S[i];

  vector<pair<int, int>> players(N);
  rep(i, N) {
    int res = 0;
    rep(j, N) {
      if (S[i][j] == 'o') {
        res++;
      }
    }
    players[i] = {i, res};
  }

  auto comp = [] (const pair<int, int>& left, const pair<int, int>& right){
    if (left.second != right.second) {
      return left.second > right.second;
    } else {
      return left.first < right.first;
    }
  };

  sort(players.begin(), players.end(), comp);
  if ((int)players.size() == 0) {
    return 0;
  }

  rep(i, N) {
    int res = players[i].first + 1;
    cout << res << " ";
  }
  cout << endl;
  return 0;
}