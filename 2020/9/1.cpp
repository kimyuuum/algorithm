#include <cstring>
#include <iostream>
using namespace std;

int main() {
  string input;
  cin >> input;
  long long res = 0;
  int idx = 0;

  while (idx < input.size()) {
    cout << idx << " " << res << endl;
    if (idx == 0) {
      if (input[idx] != 'a') {
        res += 2;
        if (input[idx + 1] == 'a') {
          idx += 2;
          if (input[idx] == 'a') {
            continue;
          } else {
            res++;
          }
          continue;
        } else {
          res += 2;
        }
      } else {
        if (input[idx + 1] == 'a') {
          idx += 2;
          if (input[idx] == 'a') {
            res = -1;
            break;
          }
          continue;
        } else {
          res++;
        }
      }
    } else {
      if (input[idx] == 'a') {
        if (input[idx + 1] == 'a') {
          idx += 2;
          if (input[idx] == 'a') {
            res = -1;
            break;
          }
          continue;
        } else {
          res++;
        }
      } else {
        if (input[idx + 1] == 'a') {
          idx += 2;
          if (input[idx] == 'a') {
            continue;
          } else {
            res++;
          }
          continue;
        } else {
          res += 2;
        }
      }
    }
    idx++;
  }

  cout << res;
  return 0;
}
