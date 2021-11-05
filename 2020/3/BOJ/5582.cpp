//
//  5582.cpp
//
//
//  Created by 김유민 on 2020/03/06.
//

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 4002;
int arr[MAX][MAX];
int length=0;

int main(){
    
    string a,b;
    cin>>a>>b;
    
    for(int i=0; i<a.size(); i++){
        for(int j=0; j<b.size(); j++){
            if(a[i] == b[j]){
                arr[i+1][j+1] = arr[i][j] + 1;
                length = max(length,arr[i+1][j+1]);
            }
        }
    }

    cout<<length;
    
    return 0;
}
