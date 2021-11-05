//
//  10866.cpp
//  
//
//  Created by 김유민 on 2019/12/20.
//

#include <iostream>
#include <deque>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int num,element;
    string command;
    deque<int> deq;
        
    cin>>num;
    
    for(int i=0; i<num; i++){
        cin>>command;
        if(command == "push_front"){
            cin>>element;
            deq.push_front(element);
        }
        else if(command == "push_back"){
            cin>>element;
            deq.push_back(element);
        }
        else if(command == "pop_front"){
            if(deq.size() != 0){
                cout<<deq.front()<<"\n";
                deq.pop_front();
            }
            else
                cout<<-1<<"\n";
        }
        else if(command == "pop_back"){
            if(deq.size() != 0){
                cout<<deq.back()<<"\n";
                deq.pop_back();
            }
            else
                cout<<-1<<"\n";
        }
        else if(command == "size"){
            cout<<deq.size()<<"\n";
        }
        else if(command == "empty"){
            if(deq.size() == 0)
                cout<<1<<"\n";
            else
                cout<<0<<"\n";
        }
        else if(command == "front"){
            if(deq.size() != 0)
                cout<<deq.front()<<"\n";
            else
                cout<<-1<<"\n";
        }
        else if(command == "back"){
            if(deq.size() != 0)
                cout<<deq.back()<<"\n";
            else
                cout<<-1<<"\n";
        }
    }
    
    return 0;
}
