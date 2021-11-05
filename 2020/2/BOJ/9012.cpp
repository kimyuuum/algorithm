//
//  9012.cpp
//  
//
//  Created by 김유민 on 2020/02/02.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    
    int T;
    vector<char> v;
    cin>>T;
    for(int i=0; i<T; i++){
        string vps;
        bool isVps = true;
        cin>>vps;
        
        for(int k=0; k<vps.size(); k++){
            if(vps[k] == '('){
                v.push_back(vps[k]);
            }
            else if(vps[k] == ')'){
                if(!v.empty())
                    v.pop_back();
                else{
                    isVps = false;
                    break;
                }
            }
        }
        
        if(!isVps)
            cout<<"NO"<<"\n";
        else{
            if(!v.empty()){
                cout<<"NO"<<"\n";
            }
            else
                cout<<"YES"<<"\n";
        }
        v.clear();
    }
    
    
    return 0;
}
