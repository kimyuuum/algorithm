
#include <cstring>
#include <iostream>
using namespace std;

int main() {
  string input;
  getline(cin, input);
  for (int i = 0; i < input.size(); i++) {
    if (input[i] == ' ') {
      input.replace(i, 1, "%20");
    }
  }
  cout << input;

  return 0;
}