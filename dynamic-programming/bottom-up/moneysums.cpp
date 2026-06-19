//this question is 0/1 knapsack variation
//target sum

#include<iostream>
#include<vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int>coins(n);
  //maximum amt we can make
  int maxi = 0;
  for(int i = 0; i < n; ++i) {
    cin >> coins[i];
    maxi += coins[i];
  }

  //we consider maxi as target, will take/skip coins, form dp table
  vector<vector<bool>>dp(n + 1, vector<bool>(maxi + 1));

  //initialisation
  //if target = 0, we can skip all coins --> can be formed
  for(int i = 0; i <= n; ++i) dp[i][0] = true;

  //if no coins given, we cannot make any sum except 0
  for(int i = 1; i <= maxi; ++i) dp[0][i] = false;

  //tabulation
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= maxi; ++j) {
      if(coins[i - 1] > j) {
        dp[i][j] = dp[i - 1][j];
      }
      else dp[i][j] = (dp[i - 1][j - coins[i - 1]] || 
                      dp[i - 1][j]);
    }
  }

    vector<int>sums;
    for(int i = 1; i <= maxi; ++i) {
      if(dp[n][i]) sums.push_back(i);
    }

    cout << sums.size() << endl;
    for(int i : sums) cout << i << " ";
}