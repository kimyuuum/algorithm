//
//  1149.cpp
//  
//
//  Created by 김유민 on 2020/03/13.
//

#include <iostream>
using namespace std;
const int MAX = 10001;
int p[MAX][4];
int d[MAX][4];

int main(){
    
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=3; j++){
            cin>>p[i][j];
        }
    }
    
    d[1][1] = p[1][1];
    d[1][2] = p[1][2];
    d[1][3] = p[1][3];
    
    for(int i=2; i<=n; i++){
        for(int j=1; j<=3; j++){
            if(j==1)
                d[i][j] = min(d[i-1][2],d[i-1][3]) + p[i][1];
            else if(j==2)
                 d[i][j] = min(d[i-1][1],d[i-1][3]) + p[i][2];
            else if(j==3)
                 d[i][j] = min(d[i-1][1],d[i-1][2]) + p[i][3];
        }
    }
    
    cout<<min(min(d[n][1],d[n][2]),d[n][3]);
    
    return 0;
}
