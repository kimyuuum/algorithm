//
//  1989.cpp
//  
//
//  Created by 김유민 on 2020/02/05.
//

#include <iostream>
#include <cstring>
using namespace std;

int main(){
    
    int T;
    string input;
    cin>>T;
    for(int i=1; i<=T; i++){
        int res = 1;
        cin>>input;
        int end = input.size()-1;
        for(int a=0; a<(input.size()/2); a++){
            if(input[a] == input[end]){
                end -= 1;
            }
            else{
                res = 0;
                break;
            }
        }
        
        cout<<"#"<<i<<" "<<res<<"\n";
    }

    return 0;
}
