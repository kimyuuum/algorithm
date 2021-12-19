#include <iostream>
#include <vector>
using namespace std;
const int MAX = 33;
int dp[3][MAX][MAX] = {
    0,
};
int map[MAX][MAX];
int N;
int res[MAX][MAX] = {
    0,
};

int main() {
  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> map[i][j];
    }
  }

  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(j-1 >= 0 && map[i][j] != 1){
        
      }
    }
  }

  return;
}