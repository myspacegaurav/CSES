//return the no. of rounds to be taken 
//in order to collect numbers from 1 to n in increasing order
//this means rounds will be increased when
//x comes first before x - 1

#include<iostream>
#include<vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> position(n + 1);
  for(int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    position[x] = i;
  }
  int rounds = 1;
  for(int i = 2; i <=n ; ++i) {
    if(position[i] < position[i - 1])
      rounds++;
  }
  cout << rounds << endl;
}