#include <iostream>
#include <set>
#include <string>
using namespace std;
set<pair<pair<int, int>, pair<int, int>>> s2;
pair<pair<int, int>, pair<int, int>> p;

bool compare(const pair<int, int>& p1, const pair<int, int>& p2) {
  if (p1.first == p2.first) {
    return p1.second < p2.second;
  }

  return p1.first < p2.first;
}

int solution(string dirs) {
  int answer = 0;
  int curX = 0;
  int curY = 0;

  for (int i = 0; i < dirs.size(); i++) {
    char command = dirs[i];
    int nextX = 0, nextY = 0;

    if (command == 'U') {
      nextX = curX;
      nextY = curY + 1;
    } else if (command == 'D') {
      nextX = curX;
      nextY = curY - 1;
    } else if (command == 'R') {
      nextX = curX + 1;
      nextY = curY;
    } else if (command == 'L') {
      nextX = curX - 1;
      nextY = curY;
    }

    if (nextX < -5 || nextX > 5 || nextY < -5 || nextY > 5) {
      continue;
    }

    if (compare({curX, curY}, {nextX, nextY})) {
      p = {{curX, curY}, {nextX, nextY}};
    } else {
      p = {{nextX, nextY}, {curX, curY}};
    }
    s2.insert(p);
    cout << p.first.first << " " << p.first.second << " " << p.second.first
         << " " << p.second.second << endl;

    curX = nextX;
    curY = nextY;
  }

  answer = s2.size();
  return answer;
}