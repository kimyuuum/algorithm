//
//  10093.cpp
//  
//
//  Created by 김유민 on 2019/12/13.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    long long a,b;
    cin>>a>>b;
    
    if(a < b){
        cout<<b-a-1<<"\n";
        for(long long i=a+1; i<b; i++){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    else if(b < a){
        cout<<a-b-1<<"\n";
        for(long long j = b+1; j<a; j++){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    else{
        cout<<0<<"\n";
    }
    
    return 0;
}
