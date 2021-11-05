//
//  2443.cpp
//  
//
//  Created by 김유민 on 2019/12/16.
//

#include <iostream>
using namespace std;

int main(){
    
    int a;
    cin>>a;
    
    for(int i=0;i<a;i++){
        for(int j=0; j<i; j++){
            cout<<" ";
        }
        for(int k=2*(a-i)-1; k>0;k--){
            cout<<"*";
        }
        cout<<"\n";
    }
    return 0;
}
