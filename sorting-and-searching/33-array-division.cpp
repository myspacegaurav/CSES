#include<iostream>
#include<vector>

using namespace std;
using ll = long long;

bool divide(vector<int>& arr, ll mid, int k) {
  int count = 1;
  ll sum = 0;
  for(int i = 0; i < arr.size(); ++i) {
    sum += arr[i];
    if(sum > mid) {
      count++;
      sum = arr[i];
    }
  }
  return count <= k;
}

int main() {
  int n, k;
  cin >> n >> k;

  int maxval = 0;
  ll totalsum = 0;
  vector<int>arr(n);

  for(int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    arr[i] = x;
    totalsum += x;
    maxval = max(maxval, x);
  }

  ll low = maxval, high = totalsum;

  while(low <= high) {
    ll mid = (low + high)/2;

    bool possible = divide(arr, mid, k);

    if(possible) high = mid - 1;
    else low = mid + 1;
  }
  cout << low << endl;
}