//
//  1912.cpp
//  
//
//  Created by 김유민 on 2020/01/28.
//

#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int d[100005];
    int a[100005];
    int n;
    cin>>n;
    
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    
    d[1] = a[1];
    
    for(int i=2; i<=n; i++){
        d[i] = max(0,d[i-1]) + a[i];
    }
    
    int max = d[1];
    
    for(int i=1; i<=n; i++){
        if(max <= d[i])
            max = d[i];
    }
    
    cout<<max;
    
    return 0;
}
