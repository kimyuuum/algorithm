//
//  5430.cpp
//  
//
//  Created by 김유민 on 2020/02/01.
//

#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>
#include <deque>
using namespace std;

deque<string> Split(string str, char delimiter){
    deque<string> internal;
    stringstream ss(str);
    string temp;
    
    while(getline(ss,temp,delimiter)){
        internal.push_back(temp);
    }
    
    return internal;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int T;
    cin>>T;
    for(int i=0; i<T; i++){
        int n;
        string command,array;
        vector<char> func;
        bool isReverse = false;
        bool isError = false;
        
        cin>>command;
        for(int j=0; j<command.size(); j++){
            func.push_back(command[j]);
        }
        
        cin>>n;
        cin>>array;
        
        if(n!=0)
            array = array.substr(1,array.size()-2);
        else
            array = "";
        
        deque<string> v = Split(array,',');
        
        
        for(int a=0; a<func.size(); a++){
            if(func[a] == 'R'){
                isReverse = !isReverse;
            }
            else if(func[a] == 'D'){
                if(v.empty()){
                    isError = true;
                    break;
                }
                else if(!isReverse){
                    v.pop_front();
                }
                else
                    v.pop_back();
            }
        }
        
        
        if(isError){
            cout<<"error"<<"\n";
        }
        else if(!v.empty()){
            if(isReverse){
                cout<<"[";
                for(int k=v.size()-1; k>0; k--){
                    cout<<v[k]<<",";
                }
                cout<<v[0]<<"]"<<"\n";
            }
            else{
                cout<<"[";
                for(int k=0; k<v.size()-1; k++){
                    cout<<v[k]<<",";
                }
                cout<<v[v.size()-1]<<"]"<<"\n";
            }
        }
        else{
            cout<<"[]"<<"\n";
        }
        
    }
    return 0;
}
