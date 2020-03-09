//
//  9252.cpp
//  
//
//  Created by 김유민 on 2020/03/06.
//

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 1000;
int arr[MAX][MAX];

int main(){
    
    string a,b;
    string res = "";

    cin>>a>>b;
    a = '0' + a;
    b = '0' + b;
    for(int i=1; i<a.size(); i++){
        for(int j=1; j<b.size(); j++){
            if(a[i] == b[j]){
                arr[i][j] = arr[i-1][j-1] + 1;
            }
            else{
                arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
            }
        }
    }

    int aIdx = a.size()-1;
    int bIdx = b.size()-1;
    
    while(aIdx != 0 && bIdx != 0){
        if(a[aIdx] == b[bIdx]){
            res = a[aIdx] + res;
            aIdx--;
            bIdx--;
        }
        else{
            if(arr[aIdx-1][bIdx] < arr[aIdx][bIdx-1]){
                bIdx--;
            }
            else{
                aIdx--;
            }
        }
    }

    cout<<arr[a.size()-1][b.size()-1]<<"\n"<<res;

    return 0;
}
