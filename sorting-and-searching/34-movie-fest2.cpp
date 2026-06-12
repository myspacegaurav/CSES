//if k = 1, one person can watch max movies having shorter ends
//finish movies as soon as possible to watch another movie
//now k = 2, if one person is busy in watching another movie and
//a movie time comes before its ending, assign to second person
//now k = 3, if movies starts after ending of first, free that person and assign this movie to watch

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<pair<int,int>> movie_time(n);

  for(int i = 0; i < n; ++i) cin >> movie_time[i].first >> movie_time[i].second;

  sort(movie_time.begin(), movie_time.end(), [](pair<int,int>& a, pair<int,int>& b) {
    return a.second < b.second;
  });

  priority_queue<int, vector<int>, greater<int>> pq;

  int watch = 0;

  for(int i = 0; i < n; ++i) {
    int start_time = movie_time[i].first;
    int end_time = movie_time[i].second;

    while(!pq.empty() && pq.top() <= start_time) {
        pq.pop();
    }
    if((int)pq.size() < k) {
      pq.push(end_time);
      watch++;
    }
  }

  cout << watch << endl;
}