#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int MAX = 100000000;
bool isPrime[MAX];
bool isUsed[MAX];

void check() {
  memset(isPrime, true, sizeof(isPrime));
  isPrime[0] = false;
  isPrime[1] = false;
  for (int i = 2; i * i <= MAX; i++) {
    if (isPrime[i]) {
      for (int j = i * i; j <= MAX; j += i) {
        isPrime[j] = false;
      }
    }
  }
}

int solution(string numbers) {
  int answer = 0;
  check();
  vector<int> v;
  for (int i = 0; i < numbers.size(); i++) {
    v.push_back(numbers[i] - '0');
  }

  sort(v.begin(), v.end());

  for (int idx = 0; idx < v.size(); idx++) {
    do {
      string num = "";
      for (int i = 0; i < v.size() - idx; i++) {
        if (i == 0 && v[i] == 0) {
          continue;
        }
        num += (v[i] + '0');
      }
      int val = atoi(num.c_str());
      if (isPrime[val] && !isUsed[val]) {
        answer++;
        isUsed[val] = true;
        cout << val << endl;
      }
    } while (next_permutation(v.begin(), v.end()));
  }
  return answer;
}

int main() {
  string numbers = "123";
  cout << solution(numbers);
  return 0;
}