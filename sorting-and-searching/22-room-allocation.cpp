//there is hotel with say k rooms
//customers come = n
//give them room with their arrival room1, room2, room3
//compare the current customer to be allocated with the min departure

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<pair<int, int>> time;

  for(int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    time.push_back({a, b});
  }

  vector<int>index(n);
  for(int i = 0; i < n; ++i) index[i] = i;
  
  //sort by arrival time while preserving index
  sort(index.begin(), index.end(), [&](int a, int b) {
    return time[a].first < time[b].first;
  });

  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
  vector<int>ans(n);
  int room = 0;

  for(int i = 0; i < n; ++i) {
    int idx = index[i];
    int arrival = time[idx].first;
    int departure = time[idx].second;

    if (!pq.empty() && pq.top().first < arrival) {
        int reused_room = pq.top().second;
        pq.pop();
        ans[idx] = reused_room;
        pq.push({departure, reused_room});
    }
    else {
        room++;
        ans[idx] = room;
        pq.push({departure, room});
    }
  }
  cout << room << endl;
  for(auto r: ans) {
    cout << r << " ";
  }

  return 0;
}