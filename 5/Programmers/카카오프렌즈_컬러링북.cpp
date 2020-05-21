#include <queue>
#include <vector>
using namespace std;
const int MAX = 101;
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {-1, 0, 1, 0};

vector<int> solution(int m, int n, vector<vector<int>> picture) {
  bool visited[MAX][MAX] = {
      false,
  };
  int number_of_area = 0;
  int max_size_of_one_area = 0;

  vector<int> answer(2);

  for (int i = 0; i < picture.size(); i++) {
    for (int j = 0; j < picture[i].size(); j++) {
      if (picture[i][j] != 0 && !visited[i][j]) {
        queue<pair<int, int>> q;
        visited[i][j] = true;
        int num = picture[i][j];
        q.push(make_pair(i, j));
        int size = 1;

        while (!q.empty()) {
          int curX = q.front().first;
          int curY = q.front().second;

          q.pop();

          for (int i = 0; i < 4; i++) {
            int nextX = curX + dirX[i];
            int nextY = curY + dirY[i];

            if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n) {
              continue;
            }
            if (picture[nextX][nextY] != num || visited[nextX][nextY]) {
              continue;
            }

            q.push(make_pair(nextX, nextY));
            visited[nextX][nextY] = true;
            size++;
          }
        }

        if (max_size_of_one_area < size) {
          max_size_of_one_area = size;
        }
        number_of_area++;
      }
    }
  }

  answer[0] = number_of_area;
  answer[1] = max_size_of_one_area;
  return answer;
}