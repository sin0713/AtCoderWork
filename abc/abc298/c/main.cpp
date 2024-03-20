#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main()
{
  int n, q;
  cin >> n >> q;

  const int card_size = 2001001;
  // card[i]が入っている箱のリスト
  vector<set<int>> card_map(card_size);
  vector<vector<int>> box_map(n+1);

  rep(qi, q)
  {
    int num;
    cin >> num;

    int i;
    cin >> i;
    if (num == 1) {
      int j;
      cin >> j;
      card_map[i].insert(j);
      box_map[j].push_back(i);
    }
    else if (num == 2) {
      vector<int> box = box_map[i];
      sort(box.begin(), box.end());
      rep(bi, box.size())
      {
        cout << box[bi] << " ";
      }
      cout << endl;
    }
    else {
      set<int> card = card_map[i];
      // sort(card.begin(), card.end());
      for (auto c : card) {
        cout << c << " ";
      }
      cout << endl;
    }
  }
  return 0;
}