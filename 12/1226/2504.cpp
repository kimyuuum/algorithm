//
//  2504.cpp
//  
//
//  Created by 김유민 on 2019/12/26.
//

#include <iostream>
#include <stack>
using namespace std;

stack<char> s;
int main(){
    
    string input;
    int result = 0;
    int res=1;
    bool isError = false;
    cin>>input;
    
    for(int i=0; i<input.size(); i++){
        if(input[i] == '('){
            res *= 2;
            s.push(input[i]);
        }
        else if(input[i] == '['){
            res *= 3;
            s.push(input[i]);
        }
        else if(input[i] == ')'){
            if(input[i-1] == '(')
                result += res;
            if(s.empty()){
                isError = true;
                break;
            }
            if(s.top() == '('){
                s.pop();
            }
            res /= 2;
        }
        else{
            if(input[i-1] == '[')
                result += res;
            if(s.empty()){
                isError = true;
                break;
            }
            if(s.top() == '[')
                s.pop();
            res /= 3;
        }
    }
    
    if(isError || !s.empty()){
        result = 0;
    }
    
    cout<<result;
    
    return 0;
}
