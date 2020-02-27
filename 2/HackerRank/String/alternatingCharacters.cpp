//
//  alternatingCharacters.cpp
//  
//
//  Created by 김유민 on 2020/02/27.
//

#include <iostream>
#include <cstring>
using namespace std;

int main(){
    
    int testcase;
    cin>>testcase;
    for(int i=0; i<testcase; i++){
        string input;
        int res = 0;
        int idx = 0;
        cin>>input;
        for(int i=1; i<input.size();i++){
            if(input[i] == input[idx]){
                res++;
            }
            else{
                idx = i;
            }
        }
        cout<<res<<"\n";
    }
    return 0;
}
