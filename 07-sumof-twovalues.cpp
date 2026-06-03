// two sum problem
//two pointer approach
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<int,int> twoSum(vector<int>& arr, int target) {
  int start = 0;
  int end = arr.size() - 1;
  while(start < end) {
    int sum = arr[start] + arr[end];
    if(sum == target) {
      return {start, end};
    }
    else if(sum < target) {
      start++;
    }
    else {
      end--;
    }
  }
  return {-1, -1};//no pair found
}

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> arr(n);
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end());
  pair<int,int> result = twoSum(arr, x);
  if(result.first != -1) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    cout << result.first << " " << result.second << endl;
  }
  return 0;
}