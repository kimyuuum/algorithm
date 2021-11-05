//
//  1914.cpp
//  
//
//  Created by 김유민 on 2020/01/26.
//

#include <iostream>
#include <vector>
using namespace std;

int n;
vector<pair<int,int> > v;

void hanoi(int num,int one,int two, int three){
    
    if(num == 1){
        v.push_back(make_pair(one,three));
    }
    else{
        //원반 n-1개를 2번 기둥으로 옮긴다
        hanoi(num-1,one,three,two);
        //가장 큰 원반을 3번 기둥으로 옮긴다
        v.push_back(make_pair(one,three));
        //나머지 기둥들을 2번에서 3번으로 옮긴다.
        hanoi(num-1,two,one,three);
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    
    if(n<=20){
        hanoi(n,1,2,3);
        cout<<v.size()<<"\n";
        for(int i=0; i<v.size(); i++){
            cout<<v[i].first<<" "<<v[i].second<<"\n";
        }
    }
    else{
        
    }
    return 0;
}
