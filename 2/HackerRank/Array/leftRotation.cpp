//
//  leftRotation.cpp
//  
//
//  Created by 김유민 on 2020/02/25.
//

#include <iostream>
using namespace std;
const int MAX = 100001;
int arr[MAX];
int res[MAX];

int main(){
    
    int n,d;
    cin>>n>>d;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    if(n != d){
        for(int idx=0; idx<n; idx++){
            if(idx - d < 0)
                res[idx-d+n] = arr[idx];
            else
                res[idx-d] = arr[idx];
        }
        
        for(int i=0; i<n; i++){
             cout<<res[i]<<" ";
         }
    }
    else{
        for(int i=0; i<n; i++){
            cout<<arr[i]<<" ";
        }
    }
    
    return 0;
}
