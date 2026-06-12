//in this, we have a restaurant and a number of customers.
//need to find the maximum number of customers at any given time
//if a customer having arrival time a1 and a1 < d0, then it means 0,1 are in the restaurant.
//so sorting the customers by their departure time, and comparing the arrival time of the next customer with the departure time of the current customer, we can find the maximum number of customers at any given time.
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int>arrivals(n), departures(n);

    for(int i = 0; i < n; ++i) {
        cin >> arrivals[i] >> departures[i];
    }

    sort(arrivals.begin(), arrivals.end());
    sort(departures.begin(), departures.end());

    int i = 0, j = 0;
    int current_customers = 0, max_customers = 0;

    while(i < n && j < n) {
        if(arrivals[i] < departures[j]) {
            current_customers++;
            max_customers = max(max_customers, current_customers);
            i++;
        }
        else{
            current_customers--;
            j++;
        }
    }

    cout << max_customers << endl;
    return 0;
}
