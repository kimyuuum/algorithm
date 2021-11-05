#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 55;
int map[MAX][MAX];
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
vector<pair<int, int>> go;
int n, m, res = 987654320;
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {-1, 0, 1, 0};

int dist() {
  int total = 0;
  for (int h = 0; h < house.size(); h++) {
    int distance = 987654321;
    int x = house[h].first;
    int y = house[h].second;

    for (int i = 0; i < go.size(); i++) {
      int tarX = go[i].first;
      int tarY = go[i].second;

      if (distance > abs(x - tarX) + abs(y - tarY)) {
        distance = abs(x - tarX) + abs(y - tarY);
      }
    }
    total += distance;
  }

  return total;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> map[i][j];
      if (map[i][j] == 2) {
        chicken.push_back({i, j});
      } else if (map[i][j] == 1) {
        house.push_back({i, j});
      }
    }
  }

  //치킨집 경우의수 돌리기
  // for (int i = 1; i <= m; i++) {
  vector<int> v;
  int k = m;
  for (int j = 0; j < k; j++) {
    v.push_back(1);
  }
  for (int j = 0; j < chicken.size() - k; j++) {
    v.push_back(0);
  }

  sort(v.begin(), v.end());

  do {
    go.clear();
    for (int i = 0; i < v.size(); i++) {
      if (v[i] == 1) {
        int x = chicken[i].first;
        int y = chicken[i].second;
        go.push_back({x, y});
      }
    }
    //해당경우의수로 치킨거리 구하기
    int dis = dist();
    if (res > dis) {
      res = dis;
    }

  } while (next_permutation(v.begin(), v.end()));
  // }

  cout << res;

  return 0;
}