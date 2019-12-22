//
//  1021.cpp
//  
//
//  Created by 김유민 on 2019/12/22.
//

#include <iostream>
#include <deque>
using namespace std;

deque<int> deq;

int main(){
        
    int num,idx,target;
    int index,count = 0;
    
    cin>>num>>idx;
    
    for(int i=1; i<=num; i++){
        deq.push_back(i);
    }
    
    for(int i=0; i<idx; i++){
        cin>>target;
        
        for(int j=0; j<deq.size(); j++){
            if(deq[j] == target)
                index = j;
        }
        
        if(deq.front() == target){
            deq.pop_front();
        }
        else{
            if(index < deq.size() - index){
                for(int n=0; n<index; n++){
                    deq.push_back(deq.front());
                    deq.pop_front();
                    count++;
                }
            }
            else{
                for(int n=deq.size(); n>index; n--){
                    deq.push_front(deq.back());
                    deq.pop_back();
                    count++;
                }
            }
            if(deq.front() == target){
                deq.pop_front();
            }
        }
    }
    
    cout<<count<<"\n";
    
    return 0;
}
