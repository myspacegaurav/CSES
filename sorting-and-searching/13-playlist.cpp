//sliding window

#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for(int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    arr[i] = k;
  }
  int maxi = 0;
  int left = 0;
  map<int, int> mp;
  for(int right = 0; right < n; ++right) {
    mp[arr[right]]++;
    while(mp[arr[right]] > 1) {
      mp[arr[left]]--;
      left++;
    }
    maxi = max(maxi, right - left + 1);
  }
  cout << maxi << endl;
}
