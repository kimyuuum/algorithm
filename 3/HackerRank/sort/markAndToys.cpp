//
//  markAndToys.cpp
//  
//
//  Created by 김유민 on 2020/03/01.
//

#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 100005;
int arr[MAX];
long k;

int main(){
    int n,input;
    cin>>n>>k;

    int idx = 0;
    
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    sort(arr,arr+n);
    
    int cnt = 0;
    
    for(int i=0; i<n; i++){
        if(k > arr[i]){
            cnt++;
            k -= arr[i];
        }
        else
            break;
    }
    
    cout<<cnt;
    return 0;
}
