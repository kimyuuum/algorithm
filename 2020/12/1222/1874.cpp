//
//  1874.cpp
//  
//
//  Created by 김유민 on 2019/12/22.
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack<int> s;
vector<char> result;

int main(){
    
    int input,index;
    int top = 0;
    cin>>input;
    
    for(int i=0; i<input; i++){
        cin>>index;
        if(top < index){
            for(int idx=top+1; idx<=index; idx++){
                s.push(idx);
                result.push_back('+');
            }
            top = s.top();
            s.pop();
            result.push_back('-');
        }
        else{
            if(index != s.top()){
                cout<<"NO"<<"\n";
                return 0;
            }
            s.pop();
            result.push_back('-');
            if(top < index){
                top = index;
            }
        }
    }
    
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<"\n";
    }
    
    return 0;
}
