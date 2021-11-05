//
//  1149.cpp
//  
//
//  Created by 김유민 on 2020/01/28.
//

#include <iostream>

using namespace std;

int main(){
    int c[10001][3] = {0,};
    int d[10001][3] = {0,};
    int n;
    cin>>n;
    
    for(int i=1; i<=n; i++){
        for(int j=0; j<3;j++){
            cin>>c[i][j];
        }
    }
    
    d[1][0] = c[1][0];
    d[1][1] = c[1][1];
    d[1][2] = c[1][2];
    
    for(int i=2; i<=n; i++){
        for(int j=0; j<3; j++){
            if(j==0){
                d[i][j] = min(d[i-1][1],d[i-1][2]) + c[i][j];
            }
            else if(j==1){
                d[i][j] = min(d[i-1][0],d[i-1][2]) + c[i][j];
            }
            else{
                d[i][j] = min(d[i-1][0],d[i-1][1]) + c[i][j];
            }
        }
    }
    
    cout<<min(d[n][0],min(d[n][1],d[n][2]));
    
    return 0;
}
