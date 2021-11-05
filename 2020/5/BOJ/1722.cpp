#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
long long fact[21];
int used[21];
int n, m;
long long k;

vector<int> v;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  fact[0] = 1;
  for (int i = 1; i < 21; i++) {
    fact[i] = fact[i - 1] * i;
  }

  cin >> m;
  if (m == 1) {
    vector<int> v(n);

    cin >> k;
    for (int i = 0; i < n; i++) {
      for (int j = 1; j <= n; j++) {
        if (used[j]) {
          continue;
        }
        if (fact[n - i - 1] < k) {
          k -= fact[n - i - 1];
        } else {
          v[i] = j;
          used[j] = true;
          break;
        }
      }
    }
    for (int i = 0; i < v.size(); i++) {
      cout << v[i] << " ";
    }
  } else {
    vector<int> v;
    int num;
    for (int i = 0; i < n; i++) {
      cin >> num;
      v.push_back(num);
    }

    for (int i = 0; i < n; i++) {
      for (int j = 1; j < v[i]; j++) {
        if (used[j]) {
          continue;
        }
        k += fact[n - i - 1];
      }
      used[v[i]] = true;
    }
    cout << k + 1;
  }

  return 0;
}