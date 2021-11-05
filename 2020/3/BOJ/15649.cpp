//
//  15649.cpp
//  
//
//  Created by 김유민 on 2020/03/10.
//

#include <iostream>
#include <vector>
using namespace std;

int n,m,k=0;
int arr[9];
vector<int> v;
bool isUsed[9];

void goback(){
    
    if(v.size() == m){
        for(int i=0; i<v.size(); i++){
            cout<<v[i]+1<<" ";
        }
        cout<<"\n";
        return;
    }
    
    for(int i=0; i<n; i++){
        if(isUsed[i])
            continue;
        else{
            v.push_back(i);
            isUsed[i] = true;
            goback();
        }
        isUsed[v[v.size()-1]] = false;
        v.pop_back();
    }
    
    
}

int main(){
    
    cin>>n>>m;
    
    goback();
    
    return 0;
}
