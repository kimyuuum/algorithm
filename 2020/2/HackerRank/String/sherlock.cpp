//
//  sherlock.cpp
//
//
//  Created by 김유민 on 2020/02/27.
//

#include <iostream>
#include <cstring>
#include <map>
using namespace std;
int cnt[26];
map<char,int> m;

int main(){
    string input;
    int max = 0, min = 100005;
    int mincnt = 0, maxcnt = 0;
    bool isValid = false;
    bool isError = false;
    cin>>input;
    for(int i=0; i<input.size(); i++){
        cnt[input[i]-97]++;
    }
    
    for(int i=0; i<26; i++){
        m[i] = cnt[i];
        if(cnt[i] != 0){
            if(cnt[i] < min)
                min = cnt[i];
            if(cnt[i] > max)
                max = cnt[i];
        }
    }
    
    for(int i=0; i<26; i++){
        if(cnt[i] != 0){
            if((cnt[i] != min) && (cnt[i] != max)){
                isError = true;
            }
        }
    }
    
    if(isError){
        cout<<"NO";
    }
    else{
        if(min == max){
            isValid = true;
        }
        else{
            map<char,int>::iterator iter;
            for(iter = m.begin(); iter!= m.end(); iter++){
                if(iter->second == min){
                    mincnt++;
                }
                else if(iter->second == max){
                    maxcnt++;
                }
            }
            if(min == 1 && mincnt == 1)
                isValid = true;
            if(maxcnt == 1 && (max - 1) == min){
                isValid = true;
            }
            else if(mincnt == 1 && (min + 1) == max){
                isValid = true;
            }
        }
        
        if(isValid)
            cout<<"YES";
        else
            cout<<"NO";
    }
    return 0;
}
