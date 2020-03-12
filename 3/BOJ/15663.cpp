//
//  15663.cpp
//  
//
//  Created by 김유민 on 2020/03/11.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 10000;

int m,n;
int arr[8];
vector<int> v;
bool visited[MAX];

void goback(){
    
    if(v.size() == m){
        for(int i=0; i<v.size(); i++){
            cout<<v[i]<<" ";
        }
        cout<<"\n";
        return;
    }

    bool isUsed[MAX] = {false,};
    
    for(int i=0; i<n; i++){
        if(isUsed[arr[i]] || visited[i])
            continue;
        v.push_back(arr[i]);
        visited[i] = true;
        isUsed[arr[i]] = true;
        goback();
        v.pop_back();
        visited[i] = false;
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
