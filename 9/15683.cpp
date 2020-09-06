#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 9;
int map[MAX][MAX];
int n, m, res = 987654321, zero = 0;
bool visited[MAX][MAX] = {
    false,
};
vector<pair<int, pair<int, int>>> cctv;

void dfs(int cnt) {
  if (cnt == cctv.size()) {
    int tmp = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!visited[i][j] && map[i][j] == 0) {
          tmp++;
        }
      }
    }
    
    if (res > tmp) {
      res = tmp;
    }

    return;
  }

  int kind = cctv[cnt].first;
  int curX = cctv[cnt].second.first;
  int curY = cctv[cnt].second.second;

  if (kind == 1) {
    for (int i = 0; i < 4; i++) {
      int x = curX;
      int y = curY;
      queue<pair<int, int>> q;

      if (i == 0) {
        while (x >= 0) {
          if (map[x][curY] == 6) {
            break;
          } else if (map[x][curY] == 0 && !visited[x][curY]) {
            visited[x][curY] = true;
            q.push(make_pair(x, curY));
          }
          x--;
        }
        dfs(cnt + 1);
        while (!q.empty()) {
          int cx = q.front().first;
          int cy = q.front().second;
          visited[cx][cy] = false;
          q.pop();
        }
      } else if (i == 1) {
        while (x < n) {
          if (map[x][curY] == 6) {
            break;
          } else if (map[x][curY] == 0 && !visited[x][curY]) {
            visited[x][curY] = true;
            q.push(make_pair(x, curY));
          }
          x++;
        }
        dfs(cnt + 1);
        while (!q.empty()) {
          int cx = q.front().first;
          int cy = q.front().second;
          visited[cx][cy] = false;
          q.pop();
        }
      } else if (i == 2) {
        while (y >= 0) {
          if (map[curX][y] == 6) {
            break;
          } else if (map[curX][y] == 0 && !visited[curX][y]) {
            visited[curX][y] = true;
            q.push(make_pair(curX, y));
          }
          y--;
        }
        dfs(cnt + 1);
        while (!q.empty()) {
          int cx = q.front().first;
          int cy = q.front().second;
          visited[cx][cy] = false;
          q.pop();
        }
      } else {
        while (y < m) {
          if (map[curX][y] == 6) {
            break;
          } else if (map[curX][y] == 0 && !visited[curX][y]) {
            visited[curX][y] = true;
            q.push(make_pair(curX, y));
          }
          y++;
        }
        dfs(cnt + 1);
        while (!q.empty()) {
          int cx = q.front().first;
          int cy = q.front().second;
          visited[cx][cy] = false;
          q.pop();
        }
      }
    }
  } else if (kind == 2) {
    for (int i = 0; i < 2; i++) {
      int x1 = curX, x2 = curX;
      int y1 = curY, y2 = curY;
      queue<pair<int, int>> q;
      if (i == 0) {
        while (y1 >= 0) {
          if (map[curX][y1] == 6) {
            break;
          } else if (map[curX][y1] == 0 && !visited[curX][y1]) {
            visited[curX][y1] = true;
            q.push(make_pair(curX, y1));
          }
          y1--;
        }

        while (y2 < m) {
          if (map[curX][y2] == 6) {
            break;
          } else if (map[curX][y2] == 0 && !visited[curX][y2]) {
            visited[curX][y2] = true;
            q.push(make_pair(curX, y2));
          }
          y2++;
        }

        dfs(cnt + 1);

        while (!q.empty()) {
          int cx = q.front().first;
          int cy = q.front().second;
          visited[cx][cy] = false;
          q.pop();
        }

      } else {
        while (x1 >= 0) {
          if (map[x1][curY] == 6) {
            break;
          } else if (map[x1][curY] == 0 && !visited[x1][curY]) {
            visited[x1][curY] = true;
            q.push(make_pair(x1, curY));
          }
          x1--;
        }
        while (x2 < n) {
          if (map[x2][curY] == 6) {
            break;
          } else if (map[x2][curY] == 0 && !visited[x2][curY]) {
            visited[x2][curY] = true;
            q.push(make_pair(x2, curY));
          }
          x2++;
        }

        dfs(cnt + 1);

        while (!q.empty()) {
          int cx = q.front().first;
          int cy = q.front().second;
          visited[cx][cy] = false;
          q.pop();
        }
      }
    }
  } else if (kind == 3) {
    for (int i = 0; i < 4; i++) {
      int x = curX;
      int y = curY;
      queue<pair<int, int>> q;

      if (i == 0) {
        while (x >= 0) {
          if (map[x][curY] == 6) {
            break;
          } else if (map[x][curY] == 0 && !visited[x][curY]) {
            visited[x][curY] = true;
            q.push(make_pair(x, curY));
          }
          x--;
        }
        while (y >= 0) {
          if (map[curX][y] == 6) {
            break;
          } else if (map[curX][y] == 0 && !visited[curX][y]) {
            visited[curX][y] = true;
            q.push(make_pair(curX, y));
          }
          y--;
        }
        dfs(cnt + 1);
        while (!q.empty()) {
          int cx = q.front().first;
          int cy = q.front().second;
          visited[cx][cy] = false;
          q.pop();
        }
      } else if (i == 1) {
        while (x >= 0) {
          if (map[x][curY] == 6) {
            break;
          } else if (map[x][curY] == 0 && !visited[x][curY]) {
            visited[x][curY] = true;
            q.push(make_pair(x, curY));
          }
          x--;
        }
        while (y < m) {
          if (map[curX][y] == 6) {
            break;
          } else if (map[curX][y] == 0 && !visited[curX][y]) {
            visited[curX][y] = true;
            q.push(make_pair(curX, y));
          }
          y++;
        }
        dfs(cnt + 1);
        while (!q.empty()) {
          int cx = q.front().first;
          int cy = q.front().second;
          visited[cx][cy] = false;
          q.pop();
        }
      } else if (i == 2) {
        while (x < n) {
          if (map[x][curY] == 6) {
            break;
          } else if (map[x][curY] == 0 && !visited[x][curY]) {
            visited[x][curY] = true;
            q.push(make_pair(x, curY));
          }
          x++;
        }
        while (y >= 0) {
          if (map[curX][y] == 6) {
            break;
          } else if (map[curX][y] == 0 && !visited[curX][y]) {
            visited[curX][y] = true;
            q.push(make_pair(curX, y));
          }
          y--;
        }
        dfs(cnt + 1);
        while (!q.empty()) {
          int cx = q.front().first;
          int cy = q.front().second;
          visited[cx][cy] = false;
          q.pop();
        }
      } else {
        while (x < n) {
          if (map[x][curY] == 6) {
            break;
          } else if (map[x][curY] == 0 && !visited[x][curY]) {
            visited[x][curY] = true;
            q.push(make_pair(x, curY));
          }
          x++;
        }
        while (y < m) {
          if (map[curX][y] == 6) {
            break;
          } else if (map[curX][y] == 0 && !visited[curX][y]) {
            visited[curX][y] = true;
            q.push(make_pair(curX, y));
          }
          y++;
        }
        dfs(cnt + 1);
        while (!q.empty()) {
          int cx = q.front().first;
          int cy = q.front().second;
          visited[cx][cy] = false;
          q.pop();
        }
      }
    }
  } else if (kind == 4) {
    for (int i = 0; i < 4; i++) {
      int x1 = curX, x2 = curX;
      int y1 = curY, y2 = curY;
      queue<pair<int, int>> q;

      if (i == 0 || i == 2) {
        if (i == 0) {
          while (x1 >= 0) {
            if (map[x1][curY] == 6) {
              break;
            } else if (map[x1][curY] == 0 && !visited[x1][curY]) {
              visited[x1][curY] = true;
              q.push(make_pair(x1, curY));
            }
            x1--;
          }
        } else if (i == 2) {
          while (x1 < n) {
            if (map[x1][curY] == 6) {
              break;
            } else if (map[x1][curY] == 0 && !visited[x1][curY]) {
              visited[x1][curY] = true;
              q.push(make_pair(x1, curY));
            }
            x1++;
          }
        }

        while (y1 >= 0) {
          if (map[curX][y1] == 6) {
            break;
          } else if (map[curX][y1] == 0 && !visited[curX][y1]) {
            visited[curX][y1] = true;
            q.push(make_pair(curX, y1));
          }
          y1--;
        }

        while (y2 < m) {
          if (map[curX][y2] == 6) {
            break;
          } else if (map[curX][y2] == 0 && !visited[curX][y2]) {
            visited[curX][y2] = true;
            q.push(make_pair(curX, y2));
          }
          y2++;
        }

        dfs(cnt + 1);
        while (!q.empty()) {
          int cx = q.front().first;
          int cy = q.front().second;
          visited[cx][cy] = false;
          q.pop();
        }
      } else if (i == 1 || i == 3) {
        if (i == 1) {
          while (y1 >= 0) {
            if (map[curX][y1] == 6) {
              break;
            } else if (map[curX][y1] == 0 && !visited[curX][y1]) {
              visited[curX][y1] = true;
              q.push(make_pair(curX, y1));
            }
            y1--;
          }
        } else if (i == 3) {
          while (y1 < m) {
            if (map[curX][y1] == 6) {
              break;
            } else if (map[curX][y1] == 0 && !visited[curX][y1]) {
              visited[curX][y1] = true;
              q.push(make_pair(curX, y1));
            }
            y1++;
          }
        }
        while (x1 >= 0) {
          if (map[x1][curY] == 6) {
            break;
          } else if (map[x1][curY] == 0 && !visited[x1][curY]) {
            visited[x1][curY] = true;
            q.push(make_pair(x1, curY));
          }
          x1--;
        }
        while (x2 < n) {
          if (map[x2][curY] == 6) {
            break;
          } else if (map[x2][curY] == 0 && !visited[x2][curY]) {
            visited[x2][curY] = true;
            q.push(make_pair(x2, curY));
          }
          x2++;
        }

        dfs(cnt + 1);

        while (!q.empty()) {
          int cx = q.front().first;
          int cy = q.front().second;
          visited[cx][cy] = false;
          q.pop();
        }
      }
    }
  } else if (kind == 5) {
    int x1 = curX, x2 = curX;
    int y1 = curY, y2 = curY;
    queue<pair<int, int>> q;

    while (y1 >= 0) {
      if (map[curX][y1] == 6) {
        break;
      } else if (map[curX][y1] == 0 && !visited[curX][y1]) {
        visited[curX][y1] = true;
        q.push(make_pair(curX, y1));
      }
      y1--;
    }

    while (y2 < m) {
      if (map[curX][y2] == 6) {
        break;
      } else if (map[curX][y2] == 0 && !visited[curX][y2]) {
        visited[curX][y2] = true;
        q.push(make_pair(curX, y2));
      }
      y2++;
    }

    while (x1 >= 0) {
      if (map[x1][curY] == 6) {
        break;
      } else if (map[x1][curY] == 0 && !visited[x1][curY]) {
        visited[x1][curY] = true;
        q.push(make_pair(x1, curY));
      }
      x1--;
    }
    while (x2 < n) {
      if (map[x2][curY] == 6) {
        break;
      } else if (map[x2][curY] == 0 && !visited[x2][curY]) {
        visited[x2][curY] = true;
        q.push(make_pair(x2, curY));
      }
      x2++;
    }

    dfs(cnt + 1);

    while (!q.empty()) {
      int cx = q.front().first;
      int cy = q.front().second;
      visited[cx][cy] = false;
      q.pop();
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> map[i][j];
      if (map[i][j] == 0) {
        zero++;
      }
      if (map[i][j] >= 1 && map[i][j] <= 5) {
        cctv.push_back({map[i][j], make_pair(i, j)});
      }
    }
  }

  if (cctv.empty()) {
    cout << zero;
  } else {
    dfs(0);
    cout << res;
  }
  return 0;
}