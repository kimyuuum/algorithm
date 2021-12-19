
#include <algorithm>
#include <iostream>
using namespace std;
const int MAX = 100001;
int cnt[MAX] = {
    0,
};
int aCnt[MAX] = {
    0,
};
int A[6] = {2, 3, 1, 4, 2, 2};
// int A[5] = {2, 3, 1, 1, 2};
int R = 3;

int main() {
  int result = 987654321;
  int leftIdx = 0;
  int rightIdx = 0 + R - 1;
  int oneCount = 0;
  int Adiff = 0;

  for (int i = 0; i < 6; i++) {
    int num = A[i];
    if (aCnt[num] == 0) {
      Adiff++;
    }
    aCnt[num]++;
  }

  for (int i = 0; i < R; i++) {
    int num = A[i];
    if (aCnt[num] == 1) {
      oneCount++;
    }
  }

  while (rightIdx < 6) {
    int nextIdx = rightIdx + 1;
    if (nextIdx == 6) {
      break;
    }

    int leftVal = A[leftIdx];
    if (aCnt[leftVal] == 1) {
      oneCount--;
    }

    int nextVal = A[nextIdx];
    if (aCnt[nextVal] == 1) {
      oneCount++;
    }

    leftIdx++;
    rightIdx++;

    if (result > oneCount) {
      result = oneCount;
    }
  }

  cout << Adiff - result;

  return 0;
}