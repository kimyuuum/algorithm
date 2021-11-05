//
//  1182.cpp
//  
//
//  Created by 김유민 on 2020/01/27.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,s;
vector<int> v;
int arr[20];

int main(){
    int idx = 1;
    int count = 0;
    cin>>n>>s;
    
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    while(idx <= n){
        v.clear();
        for(int i=0; i<idx; i++){
            v.push_back(1);
        }
        for(int i=0; i<n-idx; i++){
            v.push_back(0);
        }
        sort(v.begin(),v.end());
        
        do{
            int res = 0;
            for(int i=0; i<v.size(); i++){
                if(v[i] == 1)
                    res += arr[i];
            }
            if(res == s)
                count++;
        }while(next_permutation(v.begin(),v.end()));
        
        idx++;
    }
    
    cout<<count;
    
    return 0;
}
