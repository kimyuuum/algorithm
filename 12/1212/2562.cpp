//
//  2562.cpp
//  
//
//  Created by 김유민 on 2019/12/12.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int main(){

    int temp=0,idx,arr[9];
    
    for(int i=0; i<9; i++){
        cin>>arr[i];
        if(temp < arr[i]){
                temp = arr[i];
                idx = i + 1;
        }
    }
    
    cout<<temp<<"\n"<<idx;
    
    return 0;
}
