//귀여운 라이언
#include <iostream>
using namespace std;
const int MAX = 1000005;
int arr[MAX];

int main() {
  int n, k;
  int ryan = 0;
  int apeach = 0;
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int lidx = 0;
  int ridx = k - 1;
  int answer = 987654321;

  for (int i = 0; i < k; i++) {
    if (arr[i] == 1) {
      ryan++;
    } else {
      apeach++;
    }
  }

  if (ryan == k) {
    answer = ridx - lidx + 1;
  }

  while (1) {
    if (ryan < k) {
      ridx++;
      if (ridx == n) {
        break;
      }
      if (arr[ridx] == 1) {
        ryan++;
      } else {
        apeach++;
      }
    } else {
      if (ryan == k) {
        if (answer > ridx - lidx + 1) {
          answer = ridx - lidx + 1;
        }
      }
      if (arr[lidx] == 1) {
        ryan--;
      } else {
        apeach--;
      }
      lidx++;
      if (lidx == ridx) {
        ridx = lidx + 1;
        if (arr[lidx] == 1) {
          ryan = 1;
          if (arr[ridx] == 1) {
            ryan++;
          } else {
            apeach = 1;
          }
        } else {
          apeach = 1;
          if (arr[ridx] == 2) {
            apeach++;
          } else {
            ryan = 1;
          }
        }
      }
    }
  }
  if(answer == 987654321){
    cout<<-1;
  }else{
  cout << answer;}
  return 0;
}