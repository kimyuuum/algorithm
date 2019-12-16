//
//  2445.cpp
//  
//
//  Created by 김유민 on 2019/12/16.
//

#include <iostream>
using namespace std;

int main(){

    int input;
    cin>>input;
    
    for(int i=1; i<=input; i++){
        for(int j=0; j<i; j++){
            cout<<"*";
        }
        for(int k=2*(input-i); k>0; k--){
            cout<<" ";
        }
        for(int l=0; l<i; l++){
            cout<<"*";
        }
        cout<<"\n";
    }
    
    for(int a=1; a<=input; a++){
        for(int b=input-a; b>0; b--){
            cout<<"*";
        }
        for(int c=0; c<2*a; c++){
            cout<<" ";
        }
        for(int d=input-a; d>0; d--){
            cout<<"*";
        }
        cout<<"\n";
    }
    
    return 0;
}
