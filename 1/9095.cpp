//
//  9095.cpp
//  
//
//  Created by 김유민 on 2020/01/26.
//

#include <iostream>
#include <vector>
using namespace std;

int t,num;
int value[11];

int dfs(int num){
    
    value[1] = 1;
    value[2] = 2;
    value[3] = 4;
    
    for(int i=4; i<=num; i++){
        value[i] = value[i-1] + value[i-2] + value[i-3];
    }
    
    return value[num];
}

int main(){
    cin>>t;
    for(int i=0; i<t; i++){
        cin>>num;
        cout<<dfs(num)<<"\n";
    }
    return 0;
}
