#include <iostream>
#include <vector>
using namespace std;
int n, x;
vector<int> v;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    v.push_back(num);
  }

  for (int i = 0; i < n; i++) {
    if (v[i] < x) {
      cout << v[i] << " ";
    }
  }

  return 0;
}