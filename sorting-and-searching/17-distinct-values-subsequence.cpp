#include<iostream>
#include<vector>
#include<set>
using namespace std;

set<int> s;
int solve(vector<int>& arr, int i) {
  if(i == arr.size()) return !s.empty() ? 1 : 0;
  int result = 0;

  if(s.find(arr[i]) == s.end()) {
    s.insert(arr[i]);
    result += solve(arr, i + 1);
    s.erase(arr[i]);
  }
  result += solve(arr, i + 1);
  return result;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);

  for(int i = 0; i < n; ++i) {
   cin >> arr[i];
  }

  
  cout << solve(arr, 0);
}