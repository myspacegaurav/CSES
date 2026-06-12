//minimum time to make t products
//it can be 1, 2, 3, 4, ...., maxTime taken by factory * products
//so we have a range, and minimum constraint
//binary search

#include<iostream>
#include<vector>

using namespace std;

long long makeProduct(vector<int>& rate, long long time, int t) {
  long long p = 0;
  for(int i = 0; i < rate.size(); ++i) {
    p += time/(1LL *rate[i]);
    if(p >= t) return p;
  }
  return p;
}

int main() {
  int n, t;
  cin >> n >> t;

  vector<int>rate(n);
  int maxRate = 0;
  for(int i = 0; i < n; ++i) {
    cin >> rate[i];
    maxRate = max(maxRate, rate[i]);
  }

  long long low = 1;
  long long high = 1LL * maxRate * t;

  while(low <= high) {
    long long mid = (low + high)/2;

    long long products = makeProduct(rate, mid, t);

    if(products >= t) high = mid - 1;
    else low = mid + 1;
  }

  cout << low << endl;
}