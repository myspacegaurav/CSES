#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

int main() {
  int n, m;
  //no of concert tickets and no of customers
  cin >> n >> m;
  multiset<int>prices;
  for(int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    prices.insert(x);
  }
  vector<int>bids(m);
  for(int i = 0; i < m; ++i) {
    cin >> bids[i];
  }
  //we have to give the customer the ticket with the highest price that is less than or equal to his bid
  vector<int>bought(m, -1);
  for(int i = 0; i < m; ++i) {
    auto it = prices.upper_bound(bids[i]);
    if(it != prices.end()) {
      --it;
      bought[i] = *it;
      prices.erase(it);
    }
  } 
  for(auto &x : bought) {
    cout << x << endl;
  }
}