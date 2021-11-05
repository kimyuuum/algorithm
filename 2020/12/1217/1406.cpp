//
//  1406.cpp
//  
//
//  Created by 김유민 on 2019/12/17.
//

#include <iostream>
#include <string>
#include <list>
using namespace std;

list<char> inputList;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string input;
    int num;
    char command,add;
    
    cin>>input;
    cin>>num;
    
    for(int i=0; i<input.length(); i++){
        inputList.push_back(input[i]);
    }

    list<char>::iterator index = inputList.end();
    
    for(int i=0; i<num; i++){
        cin>>command;
        if(command == 'L'){
            if(index != inputList.begin()){
                index--;
            }
        }
        else if(command == 'D'){
            if(index != inputList.end()){
                index++;
            }
        }
        else if(command == 'B'){
            if(index != inputList.begin()){
                index = inputList.erase(--index);
            }
        }
        else if(command == 'P'){
            cin>>add;
            inputList.insert(index,add);
        }
    }
    
    for(char c : inputList){
        cout<<c;
    }
    
    return 0;
}
