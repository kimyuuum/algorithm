//
//  15656.cpp
//
//
//  Created by 김유민 on 2020/01/23.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[9];
int n,m,num;
vector<int> v;

void dfs(int count,int index){
    
    if(count == m){
        for(int i=0; i<v.size(); i++){
            cout<<v[i]<<" ";
        }
        cout<<"\n";
    }
    else{
        for(int i=index; i<n; i++){
            if(!v.empty()){
                if(v.front() > arr[i])
                    continue;
            }
            v.push_back(arr[i]);
            dfs(count+1,i);
            v.pop_back();
        }
    }
}

int main(){
    
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>num;
        arr[i] = num;
    }
    sort(arr,arr+n);
    dfs(0,0);
    
}

