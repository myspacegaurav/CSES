#include<iostream>
#include<map>

using namespace std;

int main() {
  int n;
  cin >> n;

  long long sum = 0, count = 0;
  map<long long,int> mp;
  mp[0] = 1;

  for(int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    sum += t;
    if(sum < 0) sum = ((sum % n) + n) % n;
    if(mp.count(sum % n)) count += mp[sum % n];

    mp[sum % n]++;
  }

  cout << count << endl;
}