#include<iostream>
#include<map>
#include<vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  
  for(int i = 0; i < n; ++i) cin >> arr[i];

  int left = 0;
  long long count = 0;
  map<int,int> mp;

  for(int right = 0; right < n; ++right) {
    mp[arr[right]]++;

    while(mp[arr[right]] > 1) {
      mp[arr[left]]--;
      left++;
    }
    count = count + (right - left + 1);
  }
  cout << count;
}