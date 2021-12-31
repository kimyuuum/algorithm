#include <cstring>
#include <string>
#include <vector>
using namespace std;

string solution(int n) {
  string answer = "";
  int arr[3] = {1, 2, 4};

  while (n > 0) {
    if (n % 3 == 0) {
      answer = to_string(arr[2]) + answer;
      n = n / 3 - 1;
    } else {
      int data = n % 3;
      answer = to_string(arr[data - 1]) + answer;
      n /= 3;
    }
  }
  return answer;
}