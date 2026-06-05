#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> coins(n);
  for(int i = 0; i < n; ++i) {
    cin >> coins[i];
  }

  sort(coins.begin(), coins.end());
  ll sum = 0;

  for(int &i : coins) {
    if(sum + 1 < i) {
      break;
    }
    sum += i;
  }
  cout << sum + 1 << endl;
  return 0;
}