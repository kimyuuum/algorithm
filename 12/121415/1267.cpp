//
//  1267.cpp
//  
//
//  Created by 김유민 on 2019/12/14.
//

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

int main(){
    
    int number,input;
    vector<int> sec;
    int y=0,m=0;
    
    cin>>number;
    
    for(int i=0; i<number; i++){
        cin>>input;
        sec.push_back(input);
    }
    
    for(int j=0; j<sec.size(); j++){
        y += ((sec[j] / 30) + 1) * 10;
        m += ((sec[j] / 60) + 1) * 15;
    }
    
    if(y > m){
        cout<<"M"<<" "<<m;
    }
    else if(y < m){
        cout<<"Y"<<" "<<y;
    }
    else{
        cout<<"Y M "<<y;
    }
    
    return 0;
}
