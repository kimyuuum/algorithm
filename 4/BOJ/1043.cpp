#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 52;
vector<int> v[MAX];
bool knowTrue[MAX];
bool trueParty[MAX];
bool participate[MAX][MAX];
int n, m;
queue<int> q;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int num;
    cin >> num;
    knowTrue[num] = true;
  }

  for (int i = 1; i <= m; i++) {
    int size;
    cin >> size;
    for (int s = 0; s < size; s++) {
      int num;
      cin >> num;
      participate[i][num] = true;
      if (knowTrue[num]) {
        trueParty[i] = true;
        q.push(i);
      }

      for (int k = 1; k < i; k++) {
        if (participate[k][num]) {
          v[k].push_back(i);
          v[i].push_back(k);
        }
      }
    }
  }

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    for (int i = 0; i < v[cur].size(); i++) {
      int party = v[cur][i];
      if (!trueParty[party]) {
        trueParty[party] = true;
        q.push(party);
      }
    }
  }

  int cnt = 0;

  for (int i = 1; i <= m; i++) {
    if (!trueParty[i]) {
      cnt++;
    }
  }

  cout << cnt;

  return 0;
}