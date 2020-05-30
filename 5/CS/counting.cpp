
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100;
vector<int> v = {5, 5, 3, 4, 5, 1, 0, 4, 1, 3, 0, 2, 4, 2, 3, 0};
int res[MAX];
int c[10];

int main() {
  for (int i = 0; i < v.size(); i++) {
    c[v[i]]++;
  }

  for (int i = 1; i < 10; i++) {
    c[i] += c[i - 1];
  }

  for (int i = v.size() - 1; i >= 0; i--) {
    int idx = c[v[i]];
    res[idx] = v[i];
    c[v[i]]--;
  }

  for (int i = 0; i < v.size(); i++) {
    cout << res[i] << " ";
  }
  return 0;
}