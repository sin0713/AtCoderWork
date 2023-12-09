#include <vector>
#include <algorithm>
#include <iostream>
#include <atcoder/all>
#include <math.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF (1 << 30)

struct Data 
{
  int id;
  int bet_count;
  vector<int> bet_list;

  Data() {};
  Data(int id_, int bet_count_, vector<int> bet_list_): id(id_), bet_count(bet_count_), bet_list(bet_list_) {};
};

int main() {
  int n;
  cin >> n;

  vector<Data> data_list(n);
  rep(i, n) {
    int c;
    cin >> c;

    vector<int> a(c);
    rep(j, c) cin >> a[j];

    Data d = {i, c, a};
    data_list[i] = d;
  }

  int x;
  cin >> x;

  //  xにかけた人探す
  vector<Data> result;
  rep(i, n) {
    Data data = data_list[i];
    rep(j, (int)data.bet_list.size()) {
      if (data.bet_list[j] == x) {
        result.push_back(data);
        break;
      }
    }
  }

  auto cmp = [](Data &left, Data &right) {
    if (left.bet_count != right.bet_count) {
      return left.bet_count < right.bet_count;
    } else {
      return left.id < right.id;
    }
  };

  sort(result.begin(), result.end(), cmp);

  // todo 最小値の人だけ出力する（ソート済み）
  if ((int)result.size() == 0) {
    cout << 0 << endl;
    return 0;
  }


  vector<int> ans;
  int min = result[0].bet_count;
  for (Data &d : result) {
    if (d.bet_count == min) {
      ans.push_back(d.id + 1);
    }
  }

  cout << ans.size() << endl;
  for (int i : ans) {
    cout << i << " ";
  }


  return 0;
}