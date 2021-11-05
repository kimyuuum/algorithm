//
//  9012.cpp
//  
//
//  Created by 김유민 on 2019/12/22.
//

#include <iostream>
#include <stack>
using namespace std;

int main(){
    int num;
    string vps;
    
    cin>>num;
    for(int i=0; i<num; i++){
        bool isVPS = true;
        cin>>vps;
        stack<char> s;
        
        for(int k=0; k<vps.size(); k++){
            if(vps[k] == '('){
                s.push(vps[k]);
            }
            else{
                if(!s.empty())
                    s.pop();
                else{
                    isVPS = false;
                    break;
                }
            }
        }
        if(!s.empty())
            isVPS = false;
        
        if(isVPS)
            cout<<"YES"<<"\n";
        else
            cout<<"NO"<<"\n";
        
    }
    
    return 0;
}
