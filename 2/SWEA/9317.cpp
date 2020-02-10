//
//  9317.cpp
//  
//
//  Created by 김유민 on 2020/02/10.
//

#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 100001;
char example[MAX];
char input[MAX];

int main(){
    
    int T;
    cin>>T;
    for(int test_case = 1; test_case<=T; test_case++){
        memset(example,0,sizeof(example));
        memset(input,0,sizeof(input));
        int size;
        int result = 0;
        cin>>size;
        for(int i=0; i<size; i++){
            cin>>example[i];
        }
        for(int i=0; i<size; i++){
            cin>>input[i];
        }
        
        for(int i=0; i<size; i++){
            if(example[i] == input[i])
                result++;
        }
        
        cout<<"#"<<test_case<<" "<<result<<"\n";
    }
    
    return 0;
}
