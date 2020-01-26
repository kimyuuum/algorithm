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
        hanoi(num-1,one,three,two);
        v.push_back(make_pair(one,three));
        hanoi(num-1,two,one,three);
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    
    hanoi(n,1,2,3);
    cout<<v.size()<<"\n";
    for(int i=0; i<v.size(); i++){
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    }
    
    return 0;
}
