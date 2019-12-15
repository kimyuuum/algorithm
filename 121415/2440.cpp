//
//  2440.cpp
//  
//
//  Created by 김유민 on 2019/12/15.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    
    int a;
    cin>>a;
    
    for(int j=0;j<a;j++){
        for(int i=a-j;i>0;i--){
            cout<<"*";
        }
        cout<<"\n";
    }
    
    return 0;
}
