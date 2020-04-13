#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
long long n, m;
vector<pair<long long, long long>> v;

void cntfive(long long num) {
  long long two = 0;
  for (long long i = 2; i <= num; i *= 2) {
    two += num / i;
  }

  long long five = 0;
  for (long long i = 5; i <= num; i *= 5) {
    five += num / i;
  }

  v.push_back(make_pair(two, five));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  long long k = n - m;

  cntfive(n);
  cntfive(m);
  cntfive(k);

  cout << min(v[0].first - v[1].first - v[2].first,
              v[0].second - v[1].second - v[2].second);

  return 0;
}