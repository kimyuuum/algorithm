#include <iostream>
using namespace std;
const int MAX = 41;
int arr[MAX];

int main() {
  int n, target;
  cin >> n >> target;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int left = 0;
  int right = 0;
  int sum = arr[0];

  while(right < n && left <= right){
    if(target > sum){
      right++;
      sum += arr[right];
    }else if(target < sum){
      left--;
      
    }
  }

  return 0;
}