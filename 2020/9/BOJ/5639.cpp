#include <iostream>
using namespace std;
const int MAX = 10001;
int tree[MAX];

void postOrder(int start,int end){
  if(start == end){
    return;
  }
  if(start == end - 1){
     cout<<tree[start]<<"\n";
     return;
  }

  int idx = start + 1;
  while(1){
    if((idx < end && tree[idx] < tree[start]) == false){
      break;
    }
    idx++;
  }

  postOrder(start+1,idx);
  postOrder(idx,end);

  cout<<tree[start]<<"\n";

}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int idx;

  for(idx = 0; scanf("%d",tree + idx) > 0; idx++);
  postOrder(0,idx);

  return 0;
}