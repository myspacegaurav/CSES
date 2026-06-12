//a prefix sum array
//for window in range [r - a, r- b] where r is any index
//we will maintain the min value that will be subtracted to currsum
//in general, if the min value is negative, that only can maximize
//our currsum pre[r]
//for tracking min value, we can use multiset that can be helpful
//in deleted the values that are not in range

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;
using ll = long long;

int main() {
  int n, a, b;
  cin >> n >> a >> b;

  vector<ll> prefix_sum(n + 1, 0);
  for(int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    prefix_sum[i] = prefix_sum[i - 1] + x;
  }

  multiset<ll>s;
  ll mini = 0, ans = -10e1;
  
  for(int i = 1; i <= n; ++i) {
    if(i < a) continue;
    s.insert(prefix_sum[i - a]);

    if(i > b) s.erase(s.find(prefix_sum[i - b - 1]));

    ll mini = *begin(s);
    ans = max(ans, prefix_sum[i] - mini);

  }
  cout << ans;
}

