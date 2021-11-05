//
//  5430_1.cpp
//  
//
//  Created by 김유민 on 2019/12/22.
//

#include <iostream>
#include <deque>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

deque<string> split(string str, char delimiter){
    deque<string> splitStr;
    stringstream ss(str);
    string temp;
    
    while(getline(ss,temp,delimiter)){
        splitStr.push_back(temp);
    }
    
    return splitStr;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int testcase,arrCnt;
    string strfunc,strArr;
    
    cin>>testcase;
    for(int i=0; i<testcase; i++){
        bool reverse = false;
        vector<char> func;
        deque<string> arr;
        
        cin>>strfunc;
        for(int idx=0; idx<strfunc.size(); idx++){
            func.push_back(strfunc[idx]);
        }
        
        cin>>arrCnt;
        cin>>strArr;
        
        if(arrCnt != 0){
            strArr = strArr.substr(1,strArr.size()-2);
        }
        else{
            strArr = "";
        }
        
        arr = split(strArr,',');
        
        bool hasError = false;
        for(int j=0; j<func.size(); j++){
            if(func[j] == 'R'){
                reverse = !reverse;
            }
            else if(func[j] == 'D'){
                if(arr.empty()){
                    hasError = true;
                    break;
                }
                else if(reverse){
                        arr.pop_back();
                }
                else{
                        arr.pop_front();
                    }
            }
        }
        
        if(hasError)
            cout<<"error"<<"\n";
        else if(!arr.empty()){
            if(reverse){
                cout<<"[";
                for(int n=arr.size()-1; n>0; n--){
                    cout<<arr[n]<<",";
                }
                cout<<arr[0]<<"]"<<"\n";
            }
            else{
                cout<<"[";
                for(int n=0; n<arr.size()-1; n++){
                    cout<<arr[n]<<",";
                }
                cout<<arr[arr.size()-1]<<"]"<<"\n";
            }
        }
        else{
            cout<<"[]"<<"\n";
        }
    }
    
    return 0;
}
