#include <vector>
#include <algorithm>
#include <iostream>
#include <atcoder/all>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  int M;
  cin >> N >> M;
  vector<pair<int, int>> A(M);
  vector<string> S(N);
  rep(i, M) {
    int point;
    cin >> point;
    A[i] = {i, point};
  }   
  rep(i, N) cin >> S[i];  

  vector<int> current_point_list(N);
  rep(i, N) {
    int res = 0;

    rep(j, M) {
      if (S[i][j] == 'o') {
        res += A[j].second;
      }
    }
    res += i + 1;
    current_point_list[i] = res;
  }

  auto cmp = [](const pair<int, int>& left, const pair<int, int>& right) {
    return left.second > right.second;
  };
  sort(A.begin(), A.end(), cmp);

  int max = *max_element(current_point_list.begin(), current_point_list.end());

  vector<int> result(N);
  rep(i, N) {
    int cnt = 0;
    if (current_point_list[i] >= max) {
      result[i] = cnt;
      continue;
    }

    rep(j, M) {
      if (S[i][A[j].first] == 'x') {
        cnt++;
        current_point_list[i] += A[j].second;
        if (current_point_list[i] >= max) {
          result[i] = cnt;
          break;
        }
      }
    }
  }

  rep(i, N) {
    cout << result[i] << endl;
  }
  return 0;
}