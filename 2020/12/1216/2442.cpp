//
//  2442.cpp
//  
//
//  Created by 김유민 on 2019/12/16.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    
    int a;
    cin>>a;
    
    for(int i=1; i<=a; i++){
        for(int j=0; j<a-i; j++){
            cout<<" ";
        }
        for(int k=1; k<2*i; k++){
            cout<<"*";
        }
        cout<<"\n";
    }
    
    return 0;
}
