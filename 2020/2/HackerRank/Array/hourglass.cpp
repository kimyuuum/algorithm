//
//  hourglass.cpp
//  
//
//  Created by 김유민 on 2020/02/25.
//

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int arr[6][6];

int main(){
    
    int res = -100;
    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++){
            cin>>arr[j][i];
        }
    }
    
    for(int j=0; j<4; j++){
        for(int i=0; i<4; i++){
            int temp = arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+1][j+1] + arr[i][j+2] + arr[i+1][j+2] + arr[i+2][j+2];
            res = max(res,temp);
        }
    }
    
    cout<<res;
    
    return 0;
}
