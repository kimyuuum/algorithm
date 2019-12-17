//
//  2577.cpp
//  
//
//  Created by 김유민 on 2019/12/17.
//

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int main(){
    
    int a,b,c,result = 0;
    int idx = 0;
    vector<int> numArr(10);
    string str;
    
    cin>>a>>b>>c;
    result = a*b*c;
    
    while(result != 0){
        idx = result % 10;
        numArr[idx] +=1;
        result /=10;
    }
    
    for(int i=0; i<10; i++){
        cout<<numArr[i]<<"\n";
    }
    
    return 0;
}
