//tower will formed with sorted base
//so we can binary search on bases
//if we need searching continuously - multiset

#include<iostream>
#include<set>

using namespace std;

int main() {
  int n;
  cin >> n;
  multiset<int>tower;
  int count = 0;
  for(int i = 1; i <= n; ++i) {
    int k;
    cin >> k;
    auto it = tower.upper_bound(k);
    if(it == tower.end()) {
      count++;
    }
    else {
      tower.erase(it);
    }
    tower.insert(k);
  }

  cout << count << endl;
  return 0;
}