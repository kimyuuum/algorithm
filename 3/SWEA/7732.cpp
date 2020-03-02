//
//  7732_1.cpp
//  
//
//  Created by 김유민 on 2020/03/03.
//

#include <iostream>
#include <cstring>
using namespace std;

int main(){
    
    int testcase;
    cin>>testcase;
    for(int i=1; i<=testcase; i++){
        string now,promise;
        string result="";
        
        cin>>now>>promise;
        
        int nHour = atoi(now.substr(0,2).c_str());
        int nMin = atoi(now.substr(3,2).c_str());
        int nSec = atoi(now.substr(6,2).c_str());
        
        int pHour = atoi(promise.substr(0,2).c_str());
        int pMin = atoi(promise.substr(3,2).c_str());
        int pSec = atoi(promise.substr(6,2).c_str());
        
        int res;
        
        int pres = pSec + pMin * 60 + pHour * 3600;
        int nres = nSec + nMin * 60 + nHour * 3600;
        int mres = 24 * 3600;
        
        if(pres < nres){
            res = mres - nres + pres;
        }
        else{
            res = pres - nres;
        }
        
        int rSec = res % 60;
        res /= 60;
        int rMin = res % 60;
        int rHour = res / 60;
        
        if(rHour < 10){
            result += "0" + to_string(rHour) + ":";
        }
        else if(rHour >= 10){
            result += to_string(rHour) + ":";
        }
        
        if(rMin < 10){
            result += "0" + to_string(rMin) + ":";
        }
        else if(rMin >= 0){
            result += to_string(rMin) + ":";
        }
        if(rSec < 10){
            result += "0" + to_string(rSec);
        }
        else if(rSec >= 0){
            result += to_string(rSec);
        }
        
        cout<<"#"<<i<<" "<<result<<endl;
    }
    
    return 0;
}
