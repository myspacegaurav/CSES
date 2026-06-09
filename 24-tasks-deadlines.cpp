//complete task whose completion time is less
#include<iostream>
#include<vector>
#include<algorithm>

using ll = long long;
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> time(n, vector<int>(2));

  for(int i = 0; i < n; ++i) {
    cin >> time[i][0] >> time[i][1];
  }

  sort(time.begin(), time.end());

  ll reward = 0, f_time = 0;
  for(int i = 0; i < n; ++i) {
    f_time += time[i][0];
    reward += time[i][1] - f_time;
  }

  cout << reward << endl;
  return 0;
}
