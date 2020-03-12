//
//  15666.cpp
//  
//
//  Created by 김유민 on 2020/03/12.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
int arr[8];
vector<int> v;

void goback(){
    
    if(v.size() == m){
        for(int i=0; i<v.size(); i++){
            cout<<v[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    
    bool isUsed[10000] = {false,};
    for(int i=0; i<n; i++){
        if(isUsed[arr[i]])
            continue;
        if(v.size() > 0){
            if(v[v.size()-1] > arr[i])
                continue;
        }
        v.push_back(arr[i]);
        isUsed[arr[i]] = true;
        goback();
        v.pop_back();
    }
    
}

int main(){
    
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    goback();
    
    return 0;
}
