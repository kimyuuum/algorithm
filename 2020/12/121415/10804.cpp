//
//  10804.cpp
//  
//
//  Created by 김유민 on 2019/12/15.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    
    int card[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int a,b;
    
    for(int i=0; i<10; i++){
        cin>>a>>b;
        reverse(card + (a-1),card + b);
    }
    
    for(int i=0;i<20;i++){
        cout<<card[i]<<" ";
    }
    
    return 0;
}
