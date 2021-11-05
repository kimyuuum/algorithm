//
//  2480.cpp
//  
//
//  Created by 김유민 on 2019/12/12.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    
    int arr[3];
    int count = 0,temp;
    
    for(int i=0; i<3; i++){
        cin>>arr[i];
    }
    
    sort(arr,arr+3,greater<int>());
    
    for(int i=0; i<3; i++){
        for(int j=i+1; j<3; j++){
            if(arr[i] == arr[j]){
                temp = arr[i];
                count++;
            }
        }
    }
    
    if(count == 3){
        cout<<arr[0] * 1000 + 10000;
    }
    else if(count == 1){
        cout<<temp * 100 + 1000;
    }
    else{
        cout<<arr[0] * 100;
    }
    
    return 0;
    
}
