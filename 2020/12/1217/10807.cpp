//
//  10807.cpp
//  
//
//  Created by 김유민 on 2019/12/17.
//

#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    int number,input,count = 0;
    vector<int> numArr;
    
    cin>>number;
    for(int i=0; i<number; i++){
        cin>>input;
        numArr.push_back(input);
    }

    cin>>input;
    for(int i=0; i<numArr.size(); i++){
        if(numArr[i] == input){
            count++;
        }
    }
    
    cout<<count;
    
    return 0;
}
