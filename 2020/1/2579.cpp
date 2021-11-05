//
//  2579.cpp
//  
//
//  Created by 김유민 on 2020/01/27.
//

#include <iostream>
using namespace std;

int main(){
    int d[301][2] = {0,};
    int s[300];
    int n,res = 0;
    cin>>n;
    
    for(int i=1; i<=n; i++){
        cin>>s[i];
    }
    
    d[1][0] = s[1];
    d[1][1] = 0;
    d[2][0] = s[2];
    d[2][1] = 30;
    
    for(int k=2; k<=n; k++){
        for(int j=0; j<2; j++){
            if(j==0)
                d[k][j] = max(d[k-2][0],d[k-2][1]) + s[k];
            else if(j==1)
                d[k][j] = d[k-1][0] + s[k];
        }
    }
    
    res = max(d[n][0],d[n][1]);
    
    cout<<res<<"\n";
    return 0;
}
