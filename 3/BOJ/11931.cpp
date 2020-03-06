//
//  11931.cpp
//  
//
//  Created by 김유민 on 2020/03/04.
//

#include <iostream>
using namespace std;
const int MAX = 2000010;
int arr[MAX];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n,input;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>input;
        arr[input+1000000]++;
    }
    
    for(int i=2000000; i>=0; i--){
        while(arr[i]--){
            cout<<i-1000000<<"\n";
        }
    }
    return 0;
}
