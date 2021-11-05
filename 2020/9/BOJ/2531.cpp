//회전 초밥
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 60006;
int arr[MAX];
int n, d, k, c;
vector<int> v;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> d >> k >> c;

  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    v.push_back(num);
  }

  for(int i=0; i<k; i++){
    v.push_back(v[i]);
  }

  int lidx = 0;
  int ridx = k - 1;
  int answer = 1;
  arr[c] = 1;

  for (int idx = lidx; idx <= ridx; idx++) {
    int val = v[idx];

    if (arr[val] == 0) {
      answer++;
    }
    arr[val]++;
  }

  int res = answer;

  while (lidx < n) {
    int lval = v[lidx];
    int rval = v[ridx];

    arr[lval]--;
    if (arr[lval] == 0) {
      res--;
    }

    lidx++;
    ridx++;

    rval = v[ridx];

    if (arr[rval] == 0) {
      res++;
    }

    arr[rval]++;

    if (answer < res) {
      answer = res;
    }
  }
  cout << answer;
  return 0;
}