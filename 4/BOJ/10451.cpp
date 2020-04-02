
#include <cstring>
#include <iostream>
using namespace std;
const int MAX = 1001;
int arr[MAX];
bool visited[MAX];
int res;
int n;
void dfs(int idx) {
  if (visited[idx]) {
    res++;
    return;
  }
  visited[idx] = true;
  dfs(arr[idx]);
}

int main() {
  int testcase;
  cin >> testcase;
  for (int t = 0; t < testcase; t++) {
    memset(visited, false, sizeof(visited));
    memset(arr, 0, sizeof(arr));
    res = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> arr[i];
    }
    for (int i = 1; i <= n; i++) {
      if (!visited[i]) {
        dfs(i);
      }
    }
    cout << res << "\n";
  }
  return 0;
}