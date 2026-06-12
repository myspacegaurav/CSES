//every second person is removed
//order is same left to right
//queue

#include<iostream>
#include<queue>

using namespace std;

int main() {
  int n;
  cin >> n;
  
  queue<int> q;
  for(int i = 1; i <= n; ++i) {
    q.push(i);
  }

  int i = 1;
  while(!q.empty()) {
    int child = q.front();
    q.pop();

    if(i % 2 != 0) {
      q.push(child);
    }
    else {
      cout << child << " ";
    }
    i++;
  }
}