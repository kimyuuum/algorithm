/*
1. 사이즈가 같아야 함
2. 대소문자가 구분된다.
3. 정렬보다 효율적인 방법은?
순열이라는 것은 서로가 문자열의 종류와 숫자가 같으면서 배열된 순서가 다른 것을
말한다.
*/

#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
  string a, b;
  bool isPer = true;
  cin >> a >> b;
  int asize = a.size();
  int bsize = b.size();
  if (asize != bsize) {
    isPer = false;
  } else {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < asize; i++) {
      if (a[i] != b[i]) {
        isPer = false;
        break;
      }
    }
  }

  if (isPer) {
    cout << "YES";
  } else {
    cout << "NO";
  }

  return 0;
}
