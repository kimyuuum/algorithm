//미로
#include <iostream>
#include <queue>
using namespace std;
const int MAX = 105;
char map[MAX][MAX];
int n, m,res = 987654321;
queue<pair<pair<int, int>,int>> q;
bool visited[MAX][MAX];
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {-1, 0, 1, 0};

void bfs() {
  q.push({{0, 0},1});
  visited[0][0] = true;

  while (!q.empty()) {
    int curX = q.front().first.first;
    int curY = q.front().first.second;
    int cnt = q.front().second;

    q.pop();

    if (curX == n - 1 && curY == m - 1) {
      if(res > cnt){
        res = cnt;
      }
    }

    for (int i = 0; i < 4; i++) {
      int nextX = curX + dirX[i];
      int nextY = curY + dirY[i];

      if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m) {
        continue;
      }

      if (map[nextX][nextY] != '1' || visited[nextX][nextY]) {
        continue;
      }

      q.push({make_pair(nextX, nextY),cnt+1});
      visited[nextX][nextY] = true;
    }

  }

}

int main() {

  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string input;
    cin >> input;
    for (int j = 0; j < input.size(); j++) {
      map[i][j] = input[j];
    }
  }


  bfs();
  cout<<res;

  return 0;
}
