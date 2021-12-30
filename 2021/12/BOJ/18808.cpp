#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int MAX = 41;
int n, m, k, c, r;
int map[MAX][MAX] = {
    0,
};
int sticker[10][10] = {
    0,
};

void stick(int x, int y) {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (sticker[i][j] == 1) {
        map[i + x][j + y] = 1;
      }
    }
  }
}

bool checkMap(int x, int y) {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (sticker[i][j] == 1 && map[i + x][j + y] == 1) {
        return false;
      }
    }
  }

  return true;
}

void rotate() {
  int temp[10][10] = {
      0,
  };
  memset(temp, 0, sizeof(temp));

  for (int i = 0; i < c; i++) {
    for (int j = 0, l = r - 1; j < r; j++, l--) {
      temp[i][j] = sticker[l][i];
    }
  }

  swap(r, c);
  memset(sticker, 0, sizeof(sticker));

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      sticker[i][j] = temp[i][j];
    }
  }
}

int main() {
  cin >> n >> m >> k;

  for (int idx = 0; idx < k; idx++) {
    memset(sticker, 0, sizeof(sticker));
    cin >> r >> c;

    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        cin >> sticker[i][j];
      }
    }

    bool isSticked = false;

    for (int num = 0; num < 4; num++) {
      for (int i = 0; i <= n - r; i++) {
        for (int j = 0; j <= m - c; j++) {
          if (checkMap(i, j)) {
            stick(i, j);
            isSticked = true;
            break;
          }
        }
        if (isSticked) {
          break;
        }
      }

      if (isSticked) {
        break;
      } else {
        rotate();
      }
    }
  }

  int res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (map[i][j] == 1) {
        res++;
      }
    }
  }

  cout << res;

  return 0;
}