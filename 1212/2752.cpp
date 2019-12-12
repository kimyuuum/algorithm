//
//  2752.cpp
//  
//
//  Created by 김유민 on 2019/12/12.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int arr[3];
    
    for(int i=0;i<3;i++){
        cin>>arr[i];
    }
    
    sort(arr,arr+3);
    
    for(int i=0;i<3;i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}
