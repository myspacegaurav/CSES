//lcs- longest common subsequence
//if both same value, move both pointers
//else move one by one

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int>arr1(n), arr2(m);
  for(int i = 0; i < n; ++i) cin >> arr1[i];
  for(int i = 0; i < m; ++i) cin >> arr2[i];

  vector<vector<int>>dp(n + 1, vector<int>(m + 1));

  //initialisation-- if both the arr are empty, no common at all
  //if arr2 is empty
  for(int i = 0; i <= n; ++i) dp[i][0] = 0;
  //if arr1 is empty
  for(int i = 0; i <= m; ++i) dp[0][i] = 0;

  //tabulation
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      if(arr1[i - 1] == arr2[j - 1]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      }
      
      else dp[i][j] = max(dp[i- 1][j], dp[i][j - 1]);
    }
  }
  cout << dp[n][m] << endl;

  vector<int>lcs;

  int i = n, j = m;
  while(i > 0 && j > 0) {
    if(arr1[i - 1] == arr2[j - 1]) {
      lcs.push_back(arr1[i - 1]);
      i--, j--;
    }
    else if(dp[i - 1][j] > dp[i][j - 1]) i--;
    else j--;
  }
  reverse(lcs.begin(), lcs.end());
  for(auto i : lcs) cout << i << " ";
}