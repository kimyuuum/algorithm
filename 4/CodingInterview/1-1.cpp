#include <cstring>
#include <iostream>
using namespace std;
int arr[26];

//자료구조를 사용하지 않고 풀려면 문자열을 정렬한 뒤에 투포인터를 사용해서 nlogn에 해결가능하다. 작은것부터 비교해가면서 겹치는게 있는지없는지 확인.
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string input;
  cin >> input;

  for (int i = 0; i < input.size(); i++) {
    if (input[i] >= 'A' && input[i] <= 'Z') {
      arr[input[i] - 65]++;
    } else if (input[i] >= 'a' && input[i] <= 'z') {
      arr[input[i] - 97]++;
    }
  }

  for (int i = 0; i < 26; i++) {
    if (arr[i] >= 1) {
      cout << "Duplicate";
      break;
    }
  }

  return 0;
}
