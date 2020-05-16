#include <iostream>
#include <vector>
using namespace std;
const int MAX = 101;
int n, k;
int arr[MAX];
bool use[MAX];
int plug[MAX];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    cin >> arr[i];
  }

  int cnt = 0;
  int plugIdx = 0;
  vector<int> v;

  for (int i = 0; i < k; i++) {
    if (plugIdx != n) {
      if (use[arr[i]]) {
        continue;
      }
      plug[plugIdx] = arr[i];
      use[arr[i]] = true;
      plugIdx++;
    } else {
      if (use[arr[i]]) {
        continue;
      } else {
        int distance = 0;
        int idx = 0;
        cnt++;
        for (int j = 0; j < plugIdx; j++) {
          int target = plug[j];
          int dis = 0;
          for (int a = i + 1; a < k; a++) {
            if (arr[a] == target) {
              break;
            } else {
              dis++;
            }
          }
          if (distance < dis) {
            distance = dis;
            idx = j;
          }
        }
        use[plug[idx]] = false;
        plug[idx] = arr[i];
        use[arr[i]] = true;
      }
    }
  }

  cout << cnt;
  return 0;
}