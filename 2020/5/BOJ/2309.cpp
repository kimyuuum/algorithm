#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
bool visited[11];
vector<int> v2;

void dfs(int count, int idx) {
  if (count == 7) {
    int res = 0;
    for (int i = 0; i < v2.size(); i++) {
      res += v2[i];
    }
    if (res == 100) {
      for (int i = 0; i < v2.size(); i++) {
        cout << v2[i] << "\n";
      }
      exit(0);
    }
  }

  visited[idx] = true;
  for (int i = idx + 1; i < v.size(); i++) {
    if (!visited[i]) {
      v2.push_back(v[i]);
      dfs(count + 1, i);
      v2.pop_back();
      visited[i] = false;
    }
  }
  visited[idx] = false;
}

int main() {
  for (int i = 0; i < 9; i++) {
    int num;
    cin >> num;
    v.push_back(num);
  }
  sort(v.begin(), v.end());

  for (int i = 0; i < 3; i++) {
    v2.push_back(v[i]);
    dfs(1, i);
    v2.pop_back();
  }

  return 0;
}