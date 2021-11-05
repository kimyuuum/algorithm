
#include <iostream>
using namespace std;

int main() {
  int sum = 0;
  int arr;
  for (int i = 0; i < 5; i++) {
    int num;
    cin >> num;

    if (num < 40) {
      sum += 40;
    } else {
      sum += num;
    }
  }
  cout << sum / 5;
  return 0;
}