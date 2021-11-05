//
//  15652.cpp
//  
//
//  Created by 김유민 on 2020/03/11.
//

#include <iostream>
#include <vector>
using namespace std;
int m,n;
vector<int> v;

void goback(){
    
    if(v.size() == m){
        for(int i=0; i<v.size(); i++){
            cout<<v[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    
    for(int i=1; i<=n; i++){
        if(v.size()!=0){
            if(v[v.size()-1] > i)
                continue;
            else{
                v.push_back(i);
                goback();
            }
        }
        else{
            v.push_back(i);
            goback();
        }
        v.pop_back();
    }
    
}

int main(){
    
    cin>>n>>m;
    goback();
    
    return 0;
}
