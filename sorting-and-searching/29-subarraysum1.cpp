#include<iostream>
#include<map>

using namespace std;

int main() {
  int n, x;
  cin >> n>> x;

  long long sum = 0, count = 0;
  map<long long,int> mp;
  mp[0] = 1;

  for(int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    sum += t;

    if(mp.count(sum - x)) count += mp[sum - x];

    mp[sum]++;
  }

  cout << count << endl;
}