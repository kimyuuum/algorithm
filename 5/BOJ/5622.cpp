#include <cstring>
#include <iostream>
using namespace std;

int main() {
  string input;
  cin >> input;
  int time = 0;
  for (int i = 0; i < input.size(); i++) {
    if (input[i] >= 'A' && input[i] <= 'C') {
      time += 3;
    } else if (input[i] >= 'D' && input[i] <= 'F') {
      time += 4;
    } else if (input[i] >= 'G' && input[i] <= 'I') {
      time += 5;
    } else if (input[i] >= 'J' && input[i] <= 'L') {
      time += 6;
    } else if (input[i] >= 'M' && input[i] <= 'O') {
      time += 7;
    } else if (input[i] >= 'P' && input[i] <= 'S') {
      time += 8;
    } else if (input[i] >= 'T' && input[i] <= 'V') {
      time += 9;
    } else if (input[i] >= 'W' && input[i] <= 'Z') {
      time += 10;
    }
  }

  cout << time;

  return 0;
}