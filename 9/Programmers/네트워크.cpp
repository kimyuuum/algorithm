#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
const int MAX = 205;
bool visited[MAX] = {
    false,
};
// vector<vector<int>> computers = {{1, 1, 0}, {1, 1, 1}, {0, 1, 1}};
vector<vector<int>> computers = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};

void dfs(int num) {
  visited[num] = true;
  for (int i = 0; i < computers[num].size(); i++) {
    int connect = computers[num][i];
    if (i != num) {
      if (connect && !visited[i]) {
        dfs(i);
      }
    }
  }
}

int solution(int n, vector<vector<int>> computers) {
  int answer = 0;

  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      dfs(i);
      answer++;
    }
  }

  return answer;
}

int main() {
  int n = 3;
  vector<vector<int>> computers = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
  // vector<vector<int>> computers = {{1, 1, 0}, {1, 1, 1}, {0, 1, 1}};

  cout << solution(3, computers);

  return 0;
}