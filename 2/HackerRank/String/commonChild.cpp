//
//  commonChild.cpp
//  
//
//  Created by 김유민 on 2020/02/28.
//

#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 5005;
int lcs[MAX][MAX];

int main(){
    int max = 0;
    string s1,s2;
    
    cin>>s1;
    cin>>s2;
    
    s1 = '0' + s1;
    s2 = '0' + s2;
    
    for(int i=1; i<s1.size(); i++){
        for(int j=1; j<s2.size(); j++){
            if(s1[i] == s2[j]){
                lcs[i][j] = lcs[i-1][j-1] + 1;
            }
            else{
                if(lcs[i-1][j] > lcs[i][j-1])
                    lcs[i][j] = lcs[i-1][j];
                else
                    lcs[i][j] = lcs[i][j-1];
            }
            if(max < lcs[i][j])
                max = lcs[i][j];
        }
    }
    
    cout<<max;
    
    return 0;
}
