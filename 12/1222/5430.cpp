//
//  5430.cpp
//  
//
//  Created by 김유민 on 2019/12/22.
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

vector<string> split(string str, char delimiter){
    vector<string> splitStr;
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
        vector<char> func;
        vector<string> arr;
        
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
        
        arr = split(strArr, ',');
        
        for(int j=0; j<func.size(); j++){
            if(func[j] == 'R'){
                reverse(arr.begin(),arr.end());
            }
            else if(func[j] == 'D'){
                if(arr.size() == 0){
                    cout<<"error"<<"\n";
                }
                else{
                    arr.erase(arr.begin());
                }
            }

        }
        
        if(arr.size() != 0){
            cout<<"[";
            for(int n=0; n<arr.size()-1; n++){
                cout<<arr[n]<<",";
            }
            cout<<arr[arr.size()-1]<<"]"<<"\n";
        }
    }
    
    return 0;
}
