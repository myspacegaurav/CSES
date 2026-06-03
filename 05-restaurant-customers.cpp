//in this, we have a restaurant and a number of customers.
//need to find the maximum number of customers at any given time
//if a customer having arrival time a1 and a1 < d0, then it means 0,1 are in the restaurant.
//so sorting the customers by their departure time, and comparing the arrival time of the next customer with the departure time of the current customer, we can find the maximum number of customers at any given time.
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>>customers(n);
  for(int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    customers[i] = {a, b};
  }

  sort(customers.begin(), customers.end(), [](const pair<int, int>&a, const pair<int, int>&b) {
    return a.second < b.second;
  });

  int max_customers = 1, current_customers = 1;
  int mintime = 0; 
  for(int i = 1; i < n; ++i) {
    if(customers[i].first < customers[mintime].second) {
      current_customers++;
      max_customers = max(max_customers, current_customers);
    } else {
      mintime++;
      current_customers--;
    }
  }

  cout << max_customers << endl;
  return 0;
}