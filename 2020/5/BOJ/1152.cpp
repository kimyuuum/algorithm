#include <cstring>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

vector<string> split(string str, char delimiter) {
  vector<string> internal;
  stringstream ss(str);
  string temp;

  while (getline(ss, temp, delimiter)) {
    if (temp != "") internal.push_back(temp);
  }
  return internal;
}
int main() {
  string input;
  getline(cin, input);
  vector<string> spl = split(input, ' ');
  cout << spl.size();
  return 0;
}