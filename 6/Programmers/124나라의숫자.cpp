#include <cstring>
#include <string>
#include <vector>
using namespace std;
string arr[3] = {"4","1","2"};

string solution(int n) {
    string res = "";

    while (n != 0) {
        int idx = n % 3;
        res = arr[idx] + res;
        n /= 3;
        if (idx == 0) {
          n--;
        }
    }
    
    return res;
}