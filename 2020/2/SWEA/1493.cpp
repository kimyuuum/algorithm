//
//  1493.cpp
//  
//
//  Created by 김유민 on 2020/02/26.
//

#include <iostream>
#include <vector>
using namespace std;
vector<pair<int,int> > v;

void changeV(int num){
    if(num == 1)
        v.push_back(make_pair(1,1));
    else{
        int res = 1;
        int line = 1;
        while(1){
            if(num < res + line)
                break;
            res += line;
            line++;
        }
        int val = num - res;
        int x = 1 + val;
        int y = line - val;
        v.push_back(make_pair(x,y));
    }
}

int main(){
    
    int testcase;
    cin>>testcase;
    for(int t=1; t<=testcase; t++){
        v.clear();
        int result = 0,firstValue = 1, val = 0;
        int a,b;
        int x = 0,y=0;
        cin>>a>>b;
        changeV(a);
        changeV(b);
        for(int i=0; i<v.size(); i++){
            x += v[i].first;
            y += v[i].second;
        }
        val = x + y;
        for(int i=1; i<val-1; i++){
            firstValue += i;
        }
        result = firstValue + (x - 1);
        cout<<"#"<<t<<" "<<result<<"\n";
    }
    return 0;
}
