#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int>weights(n);

  for(int i = 0; i < n; ++i) {
    cin >> weights[i];
  }

  sort(weights.begin(), weights.end());

  //first give the heavy child a seat, then fit lighter child

  int light = 0, heavy = n - 1, count = 0;

  while(light <= heavy) {
    if(weights[light] + weights[heavy] <= x) {
      ++light;
    }
    --heavy;
    ++count;
  }
  cout << count << endl;
}