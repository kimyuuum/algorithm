
#include <iostream>
using namespace std;
int n, m;

int main() {
  cin >> n >> m;
  int s = n;
  while(s < m){
    s += n;
  }
  return 0;
}