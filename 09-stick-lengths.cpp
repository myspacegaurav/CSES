//median is the value to which it lengthening and shortening of the stick length would cost minimum
//because it represents the central value

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end());

  int median = arr[n/2];
  long long total_cost = 0;
  for(int i = 0; i < n; i++) {
    total_cost += abs(arr[i] - median);
  }
  cout << total_cost << endl;
  return 0;
}