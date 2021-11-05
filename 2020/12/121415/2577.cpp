//
//  2577.cpp
//  
//
//  Created by 김유민 on 2019/12/13.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    int a,b,c,idx = 0;
    int result = 0;
    vector<int> number(10);
    
    cin>>a>>b>>c;
    result = a * b * c;
    
    while(result != 0){
        idx = result % 10;
        number[idx] += 1;
        
        result /= 10;
    }
    
    for(int i=0; i<10; i++){
        cout<<number[i]<<"\n";
    }
    
    return 0;
}
