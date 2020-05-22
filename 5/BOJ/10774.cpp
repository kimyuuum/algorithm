#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1000001;
bool isused[MAX];
vector<char> v;
int J, A;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> J >> A;
  int cnt = 0;

  for (int i = 1; i <= J; i++) {
    char input;
    cin >> input;
    v.push_back(input);
  }

  for (int i = 0; i < A; i++) {
    char size;
    int num;

    cin >> size >> num;

    if (!isused[num]) {
      if (size == 'S') {
        isused[num] = true;
        cnt++;
      } else if (size == 'M') {
        if (v[num - 1] == 'M' || v[num - 1] == 'L') {
          isused[num] = true;
          cnt++;
        }
      } else if (size == 'L') {
        if (v[num - 1] == 'L') {
          isused[num] = true;
          cnt++;
        }
      }
    }
  }

  cout << cnt << "\n";
  return 0;
}
