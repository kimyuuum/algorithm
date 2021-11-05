//
//  10799.cpp
//  
//
//  Created by 김유민 on 2020/02/03.
//

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int main(){
    
    string input;
    cin>>input;
    queue<char> stick;
    int count = 0;
    
    for(int i=0; i<input.size(); i++){
        
        if(input[i] == '('){
            stick.push(input[i]);
        }
        
        else if(input[i] == ')'){
            if(i>0 && input[i-1] == '('){
                stick.pop();
                count += stick.size();
            }
            else{
                stick.pop();
                count++;
            }
        }
    }
    
    cout<<count;
    
    return 0;
    
}
