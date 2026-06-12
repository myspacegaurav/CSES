//this question is same as previous one
//in this, the ending time will conclude the next movie's starting time
//we will watch the movie with smallest ending time, so we can watch more movies

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> movies(n);
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    movies[i] = {a, b};
  }
  sort(movies.begin(), movies.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;
  });
  int count = 0;
  int EndTime = -1;
  for(int i = 0; i < n; ++i) {
    if(i == 0 || movies[i].first >= EndTime) {
      count++;
      EndTime = movies[i].second;
    }
  }
  cout << count << endl;
}