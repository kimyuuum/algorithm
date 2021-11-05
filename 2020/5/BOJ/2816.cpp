#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
vector<string> v;

int main() {
  int n;
  cin >> n;
  int idx1 = 0;
  int idx2 = 0;
  for (int i = 0; i < n; i++) {
    string input;
    cin >> input;
    v.push_back(input);
  }

  int idx = 0;

  while (v[idx] != "KBS1") {
    cout << "1";
    idx++;
  }

  while (v[0] != "KBS1") {
    cout << "4";
    v[idx - 1].swap(v[idx]);
    idx--;
  }

  if (v[1] != "KBS2") {
    while (v[idx] != "KBS2") {
      cout << "1";
      idx++;
    }

    while (v[1] != "KBS2") {
      cout << "4";
      v[idx - 1].swap(v[idx]);
      idx--;
    }
  }

  return 0;
}