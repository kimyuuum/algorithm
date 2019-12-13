//
//  2587.cpp
//  
//
//  Created by 김유민 on 2019/12/13.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    
    int arr[5];
    int average = 0;
    
    for(int i=0; i<5; i++){
        cin>>arr[i];
        average += arr[i];
    }
    
    average /= 5;
    sort(arr,arr+5);
    
    cout<<average<<"\n"<<arr[2];
    
    return 0;
}
