

#include <iostream>
#include <vector>
using namespace std;
const int MAX = 101;
bool visited[MAX];
int arr[MAX];
int com, n;
vector<int> v[MAX];

void dfs(int idx) {
  visited[idx] = true;
  for (int i = 0; i < v[idx].size(); i++) {
    int node = v[idx][i];
    if (!visited[node]) {
      dfs(node);
    }
  }
}

int main() {
  cin >> com >> n;
  int a, b;
  for (int i = 1; i <= n; i++) {
    cin >> a >> b;
    v[a].push_back(b);
  }

  dfs(1);
  int cnt = 0;
  for (int i = 2; i <= com; i++) {
    if (visited[i]) {
      cnt++;
    }
  }
  cout << cnt;
  return 0;
}