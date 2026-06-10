#include<iostream>
#include<map>
#include<vector>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  
  for(int i = 0; i < n; ++i) cin >> arr[i];

  int left = 0;
  long long count = 0;
  map<int,int> mp;

  for(int right = 0; right < n; ++right) {
    mp[arr[right]]++;

    while(mp.size() > k) {
      mp[arr[left]]--;
      if(mp[arr[left]] == 0) mp.erase(arr[left]);
      left++;
    }
    count = count + (right - left + 1);
  }
  cout << count;
}