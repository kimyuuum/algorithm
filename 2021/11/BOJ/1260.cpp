#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 1001;
int N, M, V;
vector<int> v[MAX];
queue<int> q;
bool visited[MAX] = {false};

void dfs(int start) {
  visited[start] = true;
  cout << start << " ";

  for (int i = 0; i < v[start].size(); i++) {
    int next = v[start][i];
    if (visited[next] == false) {
      dfs(next);
    }
  }
}

void bfs(int start) {
  int index = start;
  visited[index] = true;
  q.push(index);

  while (!q.empty()) {
    index = q.front();
    for (int i = 0; i < v[index].size(); i++) {
      int next = v[index][i];

      if (visited[next] == false) {
        q.push(next);
        visited[next] = true;
      }
    }
    cout << index << " ";

    q.pop();
  }
}

int main() {
  cin >> N >> M >> V;
  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }

  for (int i = 0; i <= N; i++) {
    sort(v[i].begin(), v[i].end());
  }

  dfs(V);
  cout << endl;
  memset(visited, false, sizeof(visited));
  bfs(V);

  return 0;
}