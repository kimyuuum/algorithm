//
//  11728.cpp
//  
//
//  Created by 김유민 on 2020/03/03.
//

#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    cin>>n>>m;
    
    int a[n];
    int b[m];
    int res[n+m];
    
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<m; i++){
        cin>>b[i];
    }
    
    int aidx=0,bidx=0,idx=0;
    
    while(aidx < n && bidx < m){
        if(a[aidx] > b[bidx]){
            res[idx] = b[bidx];
            bidx++;
            idx++;
        }
        else{
            res[idx] = a[aidx];
            aidx++;
            idx++;
        }
    }
    
    while(aidx < n){
        res[idx] = a[aidx];
        aidx++;
        idx++;
    }
    while(bidx<m){
        res[idx] = b[bidx];
        bidx++;
        idx++;
    }
    
    for(int i=0; i<m+n-1; i++){
        cout<<res[i]<<" ";
    }
    cout<<res[m+n-1];
    return 0;
}
