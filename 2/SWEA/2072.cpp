//
//  2072.cpp
//  
//
//  Created by 김유민 on 2020/02/01.
//

#include <iostream>
using namespace std;

int main(){
    
    int T,num;
    cin>>T;
    for(int i=1; i<=T; ++i){
        int sum=0;
        for(int k=0; k<10; k++){
            cin>>num;
            if(num % 2 != 0)
                sum += num;
        }
        cout<<"#"<<i<<" "<<sum<<"\n";
    }
    
    return 0;
}
