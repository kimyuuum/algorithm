//
//  7728.cpp
//  
//
//  Created by 김유민 on 2020/02/09.
//

#include <iostream>
#include <cstring>
using namespace std;

int main(){
    
    int T;
    
    cin>>T;
    string input;
    for(int test_case=1; test_case<=T; test_case++){
        int arr[10] = {0,};
        int result = 0;
        cin>>input;
        for(int i=0; i<input.size(); i++){
            int idx = input[i] - 48;
            arr[idx]++;
        }
        
        for(int i=0; i<10; i++){
            if(arr[i] != 0){
                result++;
            }
        }
        
        cout<<"#"<<test_case<<" "<<result<<"\n";
    }
    
    return 0;
}
