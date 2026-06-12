#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> nums;

vector<int> twoSum(vector<int>& arr, int target, int start) {
  int end = arr.size() - 1;

  while(start < end) {
    int sum = nums[arr[start]] + nums[arr[end]];

    if(sum == target) return {arr[start], arr[end]};

    else if(sum > target) end--;

    else start++;
  }
  return {};
}

int main() {
  int n, x; 
  cin >> n >> x;

  nums.resize(n + 1, 0);
  for(int i = 1; i <= n; ++i) cin >> nums[i];

  vector<int>arr(n + 1);
  for(int i = 0; i <= n; ++i) arr[i] = i;

  sort(arr.begin(), arr.end(), [&](int a, int b) {
    return nums[a] < nums[b];
  });

  for(int i = 1; i <= n; ++i) {
    int target = x - nums[arr[i]];

    vector<int>ans = twoSum(arr, target, i + 1);

    if(!ans.empty()) {
      cout << arr[i] <<" "<< ans[0] <<" "<< ans[1];
      return 0;
    }
  }
  cout << "IMPOSSIBLE";
}