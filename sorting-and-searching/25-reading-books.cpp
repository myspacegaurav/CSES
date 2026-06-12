#include<iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  long long total_time = 0, max_time = 0;

  for(int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    total_time += t;
    max_time = max(max_time, (long long)t);
  }

  cout << max(2* max_time, total_time);
}