//
//  10845.cpp
//  
//
//  Created by 김유민 on 2019/12/20.
//

#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int num,element;
    queue<int> q;
    string command;
    
    cin>>num;
    
    for(int i=0; i<num; i++){
        cin>>command;
        if(command == "push"){
            cin>>element;
            q.push(element);
        }
        else if(command == "pop"){
            if(q.size() != 0){
                cout<<q.front()<<"\n";
                q.pop();
            }
            else
                cout<<-1<<"\n";
        }
        else if(command == "size"){
            cout<<q.size()<<"\n";
        }
        else if(command == "empty"){
            if(q.size() == 0){
                cout<<1<<"\n";
            }
            else
                cout<<0<<"\n";
        }
        else if(command == "front"){
            if(q.size() != 0){
                cout<<q.front()<<"\n";
            }
            else
                cout<<-1<<"\n";
        }
        else if(command == "back"){
            if(q.size() != 0){
                cout<<q.back()<<"\n";
            }
            else
                cout<<-1<<"\n";
        }
    }
    
    return 0;
}
