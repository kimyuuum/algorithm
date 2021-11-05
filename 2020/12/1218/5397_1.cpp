//
//  5397_1.cpp
//  
//
//  Created by 김유민 on 2019/12/19.
//

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string input;
    int num;
    
    cin>>num;
    
    for(int i=0; i<num; i++){
        cin>>input;
        stack<char> result;
        stack<char> idx;
        
        for(int j=0; j<input.length(); j++){
            if(input[j] == '<'){
                if(!result.empty()){
                    idx.push(result.top());
                    result.pop();
                }
            }
            else if(input[j] == '>'){
                if(!idx.empty()){
                    result.push(idx.top());
                    idx.pop();
                }
            }
            else if(input[j] == '-'){
                if(!result.empty())
                    result.pop();
            }
            else{
                result.push(input[j]);
            }
        }
        
        while(!idx.empty()){
            result.push(idx.top());
            idx.pop();
        }
        
        string answer;
        while(!result.empty()){
            answer += result.top();
            result.pop();
        }
        
        reverse(answer.begin(),answer.end());
        cout<<answer<<"\n";
    }
    
    return 0;
}
