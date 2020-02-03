//
//  1926.cpp
//  
//
//  Created by 김유민 on 2020/02/03.
//

#include <iostream>

using namespace std;

int check(int i){
    int count = 0;
    while(i!=0){
        int res = i % 10;
        if(res == 3||res == 6||res == 9)
            count++;
        i /= 10;
    }
    return count;
}
int main(){
    
    int N;
    cin>>N;
    
    for(int i=1; i<=N; i++){
        int count = check(i);
        if(count == 0){
            cout<<i<<" ";
        }
        else{
            for(int k=0; k<count; k++){
                cout<<"-";
            }
            cout<<" ";
        }
    }
    
    return 0;
}
