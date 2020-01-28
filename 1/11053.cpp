//
//  11053.cpp
//  
//
//  Created by 김유민 on 2020/01/28.
//

#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int d[1000];
    int a[1000];
    int n;
    
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    
    d[1] = 1;
    
    for(int i=2; i<=n; i++){
        d[i] = 1;
        for(int j=1; j<i; j++){
            if(a[j] < a[i])
                d[i] = max(d[i],d[j]+1);
        }
    }
    
    int max = d[1];
    for(int i=2; i<=n; i++){
        if(d[i] > max)
            max = d[i];
    }
    
    cout<<max;

    return 0;
}
