
#include <iostream>
using namespace std;
const int MAX = 21;
int map[MAX][MAX];
int dice[7];
int n, m, k, x, y;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m >> x >> y >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> map[i][j];
    }
  }

  while (k--) {
    int order;
    cin >> order;

    if (order == 1) {
      y++;
      if (x < 0 || x >= n || y < 0 || y >= m) {
        y--;
        continue;
      }
      int one = dice[1];
      int three = dice[3];
      int six = dice[6];
      int four = dice[4];

      dice[3] = one;
      dice[6] = three;
      dice[4] = six;
      dice[1] = four;

      cout << dice[1] << "\n";
      if (map[x][y] == 0) {
        map[x][y] = dice[6];
      } else {
        dice[6] = map[x][y];
        map[x][y] = 0;
      }

    } else if (order == 2) {
      y--;
      if (x < 0 || x >= n || y < 0 || y >= m) {
        y++;
        continue;
      }
      int one = dice[1];
      int three = dice[3];
      int six = dice[6];
      int four = dice[4];

      dice[3] = six;
      dice[6] = four;
      dice[4] = one;
      dice[1] = three;

      cout << dice[1] << "\n";
      if (map[x][y] == 0) {
        map[x][y] = dice[6];
      } else {
        dice[6] = map[x][y];
        map[x][y] = 0;
      }

    } else if (order == 3) {
      x--;

      if (x < 0 || x >= n || y < 0 || y >= m) {
        x++;

        continue;
      }
      int one = dice[1];
      int five = dice[5];
      int six = dice[6];
      int two = dice[2];

      dice[5] = six;
      dice[6] = two;
      dice[2] = one;
      dice[1] = five;

      cout << dice[1] << "\n";
      if (map[x][y] == 0) {
        map[x][y] = dice[6];
      } else {
        dice[6] = map[x][y];
        map[x][y] = 0;
      }
    } else {
      x++;
      if (x < 0 || x >= n || y < 0 || y >= m) {
        x--;
        continue;
      }
      int one = dice[1];
      int five = dice[5];
      int six = dice[6];
      int two = dice[2];

      dice[5] = one;
      dice[6] = five;
      dice[2] = six;
      dice[1] = two;

      cout << dice[1] << "\n";
      if (map[x][y] == 0) {
        map[x][y] = dice[6];
      } else {
        dice[6] = map[x][y];
        map[x][y] = 0;
      }
    }
  }

  return 0;
}