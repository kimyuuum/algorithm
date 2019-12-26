//
//  10799.cpp
//  
//
//  Created by 김유민 on 2019/12/23.
//

#include <iostream>
#include <stack>
using namespace std;

stack<char> stick;

int main(){
    
    string input;
    int count=0;
    cin>>input;
    
    for(int i=0; i<input.size(); i++){
        if(input[i] == '('){
            stick.push('(');
        }
        else{
            stick.pop();
            if(input[i-1] == '(')
                count += stick.size();
            else
                count++;
        }
    }
    
    cout<<count;
    
    return 0;
}
