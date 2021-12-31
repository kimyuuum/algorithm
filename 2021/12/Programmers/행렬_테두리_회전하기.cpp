#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int MAX = 101;
int map[MAX][MAX] = {
    0,
};

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
  vector<int> answer;
  int num = 1;

  for (int i = 1; i <= rows; i++) {
    for (int j = 1; j <= columns; j++) {
      map[i][j] = num;
      num++;
    }
  }

  for (int i = 0; i < queries.size(); i++) {
    int startX = queries[i][0];
    int startY = queries[i][1];
    int endX = queries[i][2];
    int endY = queries[i][3];

    int curX = startX;
    int curY = startY;
    int value = map[startX][startY];
    int res = value;

    while (curY != endY) {
      curY++;
      int temp = map[curX][curY];
      map[curX][curY] = value;
      value = temp;
      if (value < res) {
        res = value;
      }
    }

    while (curX != endX) {
      curX++;
      int temp = map[curX][curY];
      map[curX][curY] = value;
      value = temp;
      if (value < res) {
        res = value;
      }
    }

    while (curY != startY) {
      curY--;
      int temp = map[curX][curY];
      map[curX][curY] = value;
      value = temp;
      if (value < res) {
        res = value;
      }
    }

    while (curX != startX) {
      curX--;
      int temp = map[curX][curY];
      map[curX][curY] = value;
      value = temp;
      if (value < res) {
        res = value;
      }
    }

    answer.push_back(res);
  }

  return answer;
}