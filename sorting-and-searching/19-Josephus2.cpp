//every kth + 1 person is removed
//order is same left to right
//queue

#include<iostream>
#include<queue>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  
  queue<int> q;
  for(int i = 1; i <= n; ++i) {
    q.push(i);
  }

  while(!q.empty()) {
    int t = k % q.size();
    for (int i = 0; i < t; i++) {
      q.push(q.front());
      q.pop();
    }
    cout << q.front() << " ";
    q.pop();
  }
}