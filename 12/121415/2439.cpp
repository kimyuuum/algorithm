//
//  2439.cpp
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
    
    for(int i=1; i<=a; i++){
        for(int k=a-i; k>0; k--){
            cout<<" ";
        }
        for(int j=1; j<=i; j++){
            cout<<"*";
        }
        cout<<"\n";
    }
    return 0;
}
