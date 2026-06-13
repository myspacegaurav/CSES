#include<stdio.h>
#include <stdlib.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
int **dp;

int main() {
  int n, sum;
  scanf("%d%d", &n, &sum);
  if (n <= 0 || sum <= 0) return 1;
  dp = (int**) malloc((n + 1)* sizeof(int*));
  
  for(int i = 0; i <=n; ++i) {
    dp[i] = (int*) malloc((sum + 1)* sizeof(int));
  }

  int *coins = (int*) calloc((size_t)n, sizeof(int));
  for(int i = 0; i < n; ++i) scanf("%d", &coins[i]);

  //initialise dp with base case
  for(int i = 0; i <= sum; ++i) dp[0][i] = 10000000;

  for(int i = 0; i <= n; ++i) dp[i][0] = 0;

  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= sum; ++j) {
      if(coins[i - 1] > j)
        dp[i][j] = dp[i - 1][j];
      
      else 
        dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
    }
  }
    if(dp[n][sum] >= 10000000)
      printf("%d", -1);
    else printf("%d", dp[n][sum]);

}