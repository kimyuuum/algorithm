#include <cstring>
#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string input;
  getline(cin, input);
  if (input.size() == 1 && input == " ") {
    cout << 0;
  } else {
    int count = 1;
    for (int i = 0; i < input.size(); i++) {
      if (input[i] == ' ') {
        if (i != 0 && i != input.size() - 1) {
          count++;
        }
      }
    }

    cout << count;
  }
  return 0;
}