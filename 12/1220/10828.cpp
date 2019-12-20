//
//  10828.cpp
//  
//
//  Created by 김유민 on 2019/12/20.
//

#include <iostream>
#include <stack>
using namespace std;

int main(){
    
    int num,element;
    stack<int> s;
    string command;
    cin>>num;
    
    for(int i=0; i<num; i++){
        cin>>command;
        if(command == "push"){
            cin>>element;
            s.push(element);
        }
        else if(command == "pop"){
            if(s.size() != 0){
                cout<<s.top()<<"\n";
                s.pop();
            }
            else{
                cout<<-1<<"\n";
            }
        }
        else if(command == "size"){
            cout<<s.size()<<"\n";
        }
        else if(command == "empty"){
            if(s.size() == 0){
                cout<<1<<"\n";
            }
            else
                cout<<0<<"\n";
        }
        else if(command == "top"){
            if(s.size() != 0)
                cout<<s.top()<<"\n";
            else
                cout<<-1<<"\n";
        }
    }
    
    return 0;
}
