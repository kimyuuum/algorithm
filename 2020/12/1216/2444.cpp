//
//  2444.cpp
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
        for(int j=0; j<input-i; j++){
            cout<<" ";
        }
        for(int k=1; k<2*i; k++){
            cout<<"*";
        }
        cout<<"\n";
    }
    for(int a=1; a<input; a++){
        for(int b=0; b<a; b++){
            cout<<" ";
        }
        for(int c=2*(input-a)-1; c>0; c--){
            cout<<"*";
        }
        cout<<"\n";
    }
    
    return 0;
}
