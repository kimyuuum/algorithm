#include <iostream>
using namespace std;
const int MAX = 100001;
int arr[MAX];
int n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n;
    int input;
    for(int i=0; i<n; i++){
        cin>>input;
        arr[input]++;
    }
    
    for(int i=0; i<100001; i++){
        while(arr[i]--){
            cout<<i<<"\n";
        }
    }
    
    return 0;
}
