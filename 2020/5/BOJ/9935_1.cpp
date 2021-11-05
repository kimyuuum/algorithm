#include <cstring>
#include <iostream>
using namespace std;
const int MAX = 1000001;
char arr[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  string input, bomb;
  cin >> input >> bomb;

  int size = bomb.size();
  int pos = 0;

  for (int i = 0; i < input.size(); i++) {
    arr[pos] = input[i];
    pos++;
    if (input[i] == bomb[size - 1]) {
      int idx = bomb.size() - 1;
      int cnt = 0;
      for (int j = pos - 1; j >= pos - size; j--) {
        if (arr[j] == bomb[idx]) {
          cnt++;
        }
        idx--;
      }
      if (cnt == bomb.size()) {
        pos = pos - size;
      }
    }
  }

  if (pos == 0) {
    cout << "FRULA";
  } else {
    for (int i = 0; i < pos; i++) {
      cout << arr[i];
    }
  }
}