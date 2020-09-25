#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> histogram = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  long long answer = 0;
  int lidx = 0, ridx = histogram.size() - 1;

  while (lidx < ridx) {
    int height = min(histogram[lidx], histogram[ridx]);
    int width = ridx - lidx;

    long long value = height * width;

    if (value > answer) {
      answer = value;
    }

    if (histogram[lidx] < histogram[ridx]) {
      lidx++;
    } else {
      ridx--;
    }
  }

  cout << answer;
  return 0;
}