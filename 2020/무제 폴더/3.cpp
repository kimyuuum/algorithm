#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1001;
int n = 5;
vector<vector<int>> d = {{2, 4}, {3, 5}, {2, 5}};
int k = 3;

int solution(int n, vector<vector<int>> d, int k) {
  int answer = 0;
  vector<int> v;
  for (int i = 1; i <= n; i++) {
    v.push_back(i);
  }
  // a는 i-1번째에있음
  for (int i = 0; i < d.size(); i++) {
    int aidx = d[i][0];
    int bidx = d[i][1];

    int temp = v[aidx - 1];  // a번째에 있는 값
    v[aidx - 1] = v[bidx - 1];
    v[bidx - 1] = temp;

  }

  for (int i = 0; i < v.size(); i++) {
    if (v[i] == k) {
      answer = i;
      break;
    }
  }
  return answer;
}

int main() {
  solution(n, d, k);
  return 0;
}
