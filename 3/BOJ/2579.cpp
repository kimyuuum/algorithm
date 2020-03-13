//
//  2579.cpp
//  
//
//  Created by 김유민 on 2020/03/13.
//

#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 300;
int d[MAX][3];
int s[300];

int main(){
    
    int stair;
    cin>>stair;
    
    for(int i=1; i<=stair; i++){
        cin>>s[i];
    }
    
    d[1][1] = s[1];
    d[1][2] = 0;
    d[2][1] = s[2];
    d[2][2] = d[1][1] + s[2];
    
    for(int i=3; i<=stair; i++){
        for(int j=1; j<=2; j++){
            if(j==1)
                d[i][j] = max(d[i-2][1],d[i-2][2]) + s[i];
            else if(j==2)
                d[i][j] = d[i-1][1] + s[i];
        }
    }
    
    cout<<max(d[stair][1],d[stair][2]);
    
    
    return 0;
}
