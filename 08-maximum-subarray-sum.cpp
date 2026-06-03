//Kadane's Algorithm

#include<iostream>
#include<vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int maxSum = INT_MIN;
  int sum = 0;
  for(int &num : arr) {
    sum += num;
    maxSum = max(maxSum, sum);
    if (sum < 0) {
      sum = 0;
    }
  }
  cout << maxSum << endl;
  return 0;
}