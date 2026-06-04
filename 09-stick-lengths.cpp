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
  cout << median << endl;
  return 0;
}