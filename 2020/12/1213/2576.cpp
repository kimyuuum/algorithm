//
//  2576.cpp
//  
//
//  Created by 김유민 on 2019/12/13.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    
    int arr[7];
    int minValue = 100, result = 0;
    
    for(int i=0; i<7; i++){
        cin>>arr[i];
        if(arr[i] % 2 != 0){
            result += arr[i];
            if(arr[i] < minValue){
                minValue = arr[i];
            }
        }
    }
    
    if(result == 0){
        cout<<-1;
    }
    else{
        cout<<result<<"\n"<<minValue;
    }
    
    return 0;
}
