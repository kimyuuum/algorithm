//
//  2504.cpp
//  
//
//  Created by 김유민 on 2020/02/03.
//

#include <iostream>
#include <stack>
using namespace std;

int main(){
    
    string input;
    int result = 0;
    int res = 1;
    bool isError = false;
    stack<char> q;
    
    cin>>input;
    
    for(int i=0; i<input.size(); i++){
        if(input[i] == '('){
            res *= 2;
            q.push(input[i]);
        }
        else if(input[i] == '['){
            res *= 3;
            q.push(input[i]);
        }
        else if(input[i] == ')'){
            if(input[i-1] == '(')
                result += res;
            if(q.empty()){
                isError = true;
                break;
            }
            if(q.top() == '(')
                q.pop();
            res /= 2;
        }
        else{
            if(input[i-1] == '[')
                result += res;
            if(q.empty()){
                isError = true;
                break;
            }
            if(q.top() == '[')
                q.pop();
            res /= 3;
        }
    }
    
    if(isError || !q.empty()){
        result = 0;
    }
    cout<<result;
    return 0;
}
