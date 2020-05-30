
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> v = {152, 73, 69, 41, 28, 1247, 2, 33, 674, 388};
queue<int> q[10];

int main() {
  int max = 1;
  for (int i = 0; i < v.size(); i++) {
    if (max < v[i]) {
      while (max < v[i]) {
        max *= 10;
      }
    }
  }

  int mod = 10;

  while (mod <= max) {
    for (int i = 0; i < v.size(); i++) {
      if (mod > v[i]) {
        q[0].push(v[i]);
      } else {
        int num = (v[i] / mod) % 10;
        q[num].push(v[i]);
      }
    }

    int idx = 0;
    for (int i = 0; i < 10; i++) {
      if (!q[i].empty()) {
        while (!q[i].empty()) {
          v[idx] = q[i].front();
          q[i].pop();
          idx++;
        }
      }
    }
    mod *= 10;
  }

  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  return 0;
}
