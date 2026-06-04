#include<iostream>
#include<set>

using namespace std;

int main() {
  int n, x;
  set<int>s;
  cin >> n;
  //enter stream of integers
  //and store it in set
  //size of set will give distinct elements no
  for(int i = 0; i < n; ++i) {
    cin >> x;
    s.insert(x);
  }

  cout << s.size() << endl;
}