//
//  2446.cpp
//  
//
//  Created by 김유민 on 2019/12/16.
//

#include <iostream>
using namespace std;

int main(){
    
    int input;
    cin>>input;
    
    for(int i=0; i<input; i++){
        for(int k1=0; k1<i; k1++){
            cout<<" ";
        }
        for(int j=2*(input-i)-1; j>0; j--){
            cout<<"*";
        }
        cout<<"\n";
    }
    
    for(int a=1; a<input; a++){
        for(int b=0; b<input-a-1; b++){
            cout<<" ";
        }
        for(int c=0; c<2*(a+1)-1; c++){
            cout<<"*";
        }
        cout<<"\n";
    }
    
    return 0;
}
