//
//  6443.cpp
//  
//
//  Created by 김유민 on 2020/01/26.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int n;
string word;
vector<char> v;
char arr[1000];
bool visited[1000];

void dfs(int count){
    
    if(count == word.length()){
        for(int i=0; i<v.size(); i++){
            cout<<v[i];
        }
        cout<<"\n";
    }
    else{
        bool used[1000] = {false,};
        for(int i=0; i<word.length(); i++){
            if(used[arr[i]])
                continue;
            if(visited[i] == true)
                continue;
            visited[i] = true;
            used[arr[i]] = true;
            v.push_back(arr[i]);
            dfs(count+1);
            v.pop_back();
            visited[i] = false;
        }
    }
}

int main(){
    
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>word;
        strcpy(arr,word.c_str());
        sort(arr,arr+word.size());
        dfs(0);
        memset(arr,0,sizeof(arr));
    }
    
    return 0;
}
