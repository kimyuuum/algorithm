
#include <cstring>
#include <deque>
#include <iostream>
using namespace std;
deque<int> d[5];
bool rot[3];
int k, idx, num, r;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string input;
  for (int i = 1; i <= 4; i++) {
    cin >> input;
    for (int j = 0; j < input.size(); j++) {
      d[i].push_back(input[j] - '0');
    }
  }

  cin >> k;
  while (k--) {
    cin >> idx >> r;
    memset(rot, false, sizeof(rot));
    if (d[1][2] != d[2][6]) {
      rot[0] = true;
    }
    if (d[2][2] != d[3][6]) {
      rot[1] = true;
    }
    if (d[3][2] != d[4][6]) {
      rot[2] = true;
    }
    if (idx == 1) {
      // 1번바퀴는 무조건 rotate시킨다 방향체크하고
      // rotate target number = 0;
      //만약 rotate[]이 true면 방향바꿔서 rotate시킨다
      //그리고 rotate target number ++ ;
      //만약 rotate[]이 true면 방향바꿔서 rotate 시킨다
      if (r == 1) {
        int temp = d[idx].back();
        d[idx].pop_back();
        d[idx].push_front(temp);
      } else {
        int temp = d[idx].front();
        d[idx].pop_front();
        d[idx].push_back(temp);
      }
      int right = idx + 1;
      // while 4까지
      while (right <= 4) {
        int rIdx = right - 2;
        r *= -1;
        if (!rot[rIdx]) {
          break;
        } else {
          if (r == 1) {
            int temp = d[right].back();
            d[right].pop_back();
            d[right].push_front(temp);
          } else {
            int temp = d[right].front();
            d[right].pop_front();
            d[right].push_back(temp);
          }
        }
        right++;
      }
    } else if (idx == 4) {
      if (r == 1) {
        int temp = d[idx].back();
        d[idx].pop_back();
        d[idx].push_front(temp);
      } else {
        int temp = d[idx].front();
        d[idx].pop_front();
        d[idx].push_back(temp);
      }

      int left = idx - 1;
      // while 1까지
      while (left >= 1) {
        int rIdx = left - 1;
        r *= -1;
        if (!rot[rIdx]) {
          break;
        } else {
          if (r == 1) {
            int temp = d[left].back();
            d[left].pop_back();
            d[left].push_front(temp);
          } else {
            int temp = d[left].front();
            d[left].pop_front();
            d[left].push_back(temp);
          }
        }
        left--;
      }
    } else {
      if (r == 1) {
        int temp = d[idx].back();
        d[idx].pop_back();
        d[idx].push_front(temp);
      } else {
        int temp = d[idx].front();
        d[idx].pop_front();
        d[idx].push_back(temp);
      }

      int left = idx - 1;
      int right = idx + 1;
      int rr = r;
      int lr = r;
      while (right <= 4) {
        int rIdx = right - 2;
        rr *= -1;
        if (!rot[rIdx]) {
          break;
        } else {
          if (rr == 1) {
            int temp = d[right].back();
            d[right].pop_back();
            d[right].push_front(temp);
          } else {
            int temp = d[right].front();
            d[right].pop_front();
            d[right].push_back(temp);
          }
        }

        right++;
      }

      while (left >= 1) {
        int rIdx = left - 1;
        lr *= -1;
        if (!rot[rIdx]) {
          break;
        } else {
          if (lr == 1) {
            int temp = d[left].back();
            d[left].pop_back();
            d[left].push_front(temp);
          } else {
            int temp = d[left].front();
            d[left].pop_front();
            d[left].push_back(temp);
          }
        }

        left--;
      }
    }
  }

  int res = 0;
  if (d[1].at(0) == 1) {
    res += 1;
  }
  if (d[2].at(0) == 1) {
    res += 2;
  }
  if (d[3].at(0) == 1) {
    res += 4;
  }
  if (d[4].at(0) == 1) {
    res += 8;
  }
  cout << res;
  return 0;
}