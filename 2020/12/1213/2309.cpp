//
//  2309.cpp
//  
//
//  Created by 김유민 on 2019/12/13.
//

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


int main(){
    
    vector<int> height;
    int value = 0;
    int result = 0;
    
    for(int i=0; i<9; i++){
        cin>>value;
        height.push_back(value);
        result += height[i];
    }
    
    sort(height.begin(),height.end());
    
    for(int i=0; i<8; i++){
        for(int j=i+1; j<9; j++){
            if( (result - height[i] - height[j]) == 100 ){
                for(int k =0; k<9; k++){
                    if(k != i && k != j){
                        cout<<height[k]<<"\n";
                    }
                }
                return 0;
            }
        }
    }

    return 0;
}
