#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 30003;
int main() {
  vector<string> input = {"zzzz", "ferz", "zdsr", "fgtd"};
  vector<int> v[MAX];
  vector<int> res;

  for (int i = 0; i < input.size(); i++) {
    for (int j = 0; j < input[i].size(); j++) {
      char ch = input[i][j];
      v[i].push_back(ch - 97);
    }
  }

  int size = v[0].size();
  bool fin = false;

  for (int i = 0; i < input.size(); i++) {
    for (int j = i + 1; j < input.size(); j++) {
      int idx = 0;
      while (idx < size) {
        if (v[i][idx] == v[j][idx]) {
          res.push_back(i);
          res.push_back(j);
          res.push_back(idx);
          fin = true;
          break;
        }
        idx++;
      }
      if (fin) {
        break;
      }
    }
    if (fin) {
      break;
    }
  }

  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }

  return 0;
}