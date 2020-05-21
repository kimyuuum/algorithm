#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 51;
vector<int> v[MAX];
bool erased[MAX];
int n;

void dfs(int num) {
  if (v[num].size() == 0) {
    erased[num] = true;
    return;
  }

  erased[num] = true;
  for (int i = 0; i < v[num].size(); i++) {
    dfs(v[num][i]);
  }
}

int main() {
  cin >> n;

  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    if (num != -1) {
      v[num].push_back(i);
    }
  }

  int num;
  cin >> num;

  dfs(num);

  int cnt = 0;

  for (int i = 0; i < n; i++) {
    int size = v[i].size();
    if (size == 0) {
      if (!erased[i]) {
        cnt++;
      }
    } else {
      if (!erased[i]) {
        int c = 0;
        for (int j = 0; j < size; j++) {
          int node = v[i][j];
          if (erased[node]) {
            c++;
          }
        }
        if (c == size) {
          cnt++;
        }
      }
    }
  }

  cout << cnt;
  return 0;
}