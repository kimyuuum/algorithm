//
//  specialString.cpp
//  
//
//  Created by 김유민 on 2020/02/28.
//
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const long MAX = 100006;
char arr[MAX];
int res = 0;
int n;
vector<pair<char,int> > v;

int main(){
    
    cin>>n;
    char input;
    
    for(int i=0; i<n; i++){
        cin>>input;
        if(v.empty()){
            v.push_back(make_pair(input,1));
        }
        if(i!=0){
            if(v.back().first == input){
                int cnt = v.back().second;
                cnt++;
                v.back().second = cnt;
            }
            else{
                v.push_back(make_pair(input,1));
            }
        }
    }
    
    for(int i=0; i<v.size(); i++){
        if(v[i].second == 1)
            res += v[i].second;
        else{
            for(int j=1; j<=v[i].second;j++){
                res += j;
            }
        }
    }

    for(int i=1; i<v.size(); i++){
        if(v[i].second == 1 && v[i-1].first == v[i+1].first){
            res += min(v[i-1].second,v[i+1].second);
        }
    }
    
    cout<<res;
    
    return 0;
    
}
