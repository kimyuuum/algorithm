#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

int solution(int N) {
  int result = 0;
  stack<int> s;
  int oneCount = 0;

  while (N > 0) {
    int data = N % 2;
    if (data == 1) {
      oneCount++;
    }
    s.push(data);
    N = N / 2;
  }

  if (oneCount == 1) {
    return result;
  } else {
    bool isCounting = false;
    int length = 0;

    while (!s.empty()) {
      if (isCounting == false && s.top() == 1) {
        isCounting = true;
      } else if (isCounting == true) {
        if (s.top() == 0) {
          length++;
        } else {
          if (result < length) {
            result = length;
          }
          length = 0;
        }
      }
      s.pop();
    }
  }

  return result;
}

int main() {
  int num;
  cin >> num;
  int result = solution(num);
  cout << result;
  return 0;
}