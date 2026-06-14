//at every cell , we will ask, how many ways to come at this cell
//dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//by this , at dp[n][n] , it will tell no. of ways to reach at n,n

#include<stdio.h>
#include<stdlib.h>

#define MOD 1000000007
typedef long long ll;

int main() {
  int n;
  scanf("%d", &n);

  char **mat = (char**) malloc((n)* sizeof(char*));
  for(int i = 0; i < n; ++i) {
    mat[i] = (char*) malloc((n) * sizeof(char));
  }

  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
      scanf(" %c", &mat[i][j]);


  ll **dp = (ll**) malloc((n)* sizeof(ll*));
  for(int i = 0; i <n; ++i) {
    dp[i] = (ll*) malloc((n) * sizeof(ll));
  }

  dp[0][0] = (mat[0][0] == '*')? 0 : 1;
  //there is only 1 way to move in first row
  for(int i = 1; i < n; ++i) {
    if(mat[0][i] == '*') dp[0][i] = 0;
    else dp[0][i] = dp[0][i - 1];
  }

  //there is only 1 way to move in first col
  for(int i= 1; i < n; ++i) {
    if(mat[i][0] == '*') dp[i][0] = 0;
    else dp[i][0] = dp[i - 1][0];
  }

  for(int i = 1; i < n; ++i) {
    for(int j = 1; j < n; ++j) {
      if(mat[i][j] == '*') dp[i][j] = 0;
      else dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
    }
  }
  printf("%lld", dp[n - 1][n - 1]);
}