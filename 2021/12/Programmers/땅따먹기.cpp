#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100001;
int map[4][MAX][4] = {
    0,
};

int solution(vector<vector<int> > land) {
  int answer = 0;

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (j == i) {
        continue;
      }
      map[j][1][i] = land[0][j] + land[1][i];
    }
  }

  for (int n = 2; n < land.size(); n++) {
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        int beforeVal = 0;

        if (i == j) {
          continue;
        }

        //여기서 [?][n-1][j]중에 max값 뽑아야됨
        for (int k = 0; k < 4; k++) {
          if (map[k][n - 1][j] > beforeVal) {
            beforeVal = map[k][n - 1][j];
          }
        }

        map[j][n][i] = land[n][i] + beforeVal;
      }
    }
  }

  int idx = land.size() - 1;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (answer < map[i][idx][j]) {
        answer = map[i][idx][j];
      }
    }
  }
  return answer;
}