//암기왕
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int testcase;
  cin>>testcase;

  while(testcase--){
    int a,b;
    vector<int> v1;
    vector<int> v2;
    cin>>a;
    for(int i=0; i<a; i++){
      int num;
      cin>>num;
      v1.push_back(num);
    }
    cin>>b;
    for(int i=0; i<b; i++){
      int num;
      cin>>num;
      v2.push_back(num);
    }

    sort(v1.begin(),v1.end());

    for(int i=0; i<b; i++){
      if(binary_search(v1.begin(),v1.end(),v2[i])){
        cout<<1<<"\n";
      }else{
        cout<<0<<"\n";
      }
    }
  }

  return 0;
}