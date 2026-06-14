#include<stdio.h>
#include<stdlib.h>

int main() {
  int n, sum;
  scanf("%d%d", &n, &sum);

  int *coins = (int*) malloc((n + 1) * sizeof(int));
  for (int i = 0; i < n; ++i) scanf("%d", &coins[i]);


  int **dp = (int**) malloc((n + 1) * sizeof(int*));

  for(int i = 0; i <= n; ++i) {
    dp[i] = (int*) malloc((sum + 1) * sizeof(int));
    for(int j = 0; j <= sum; ++j) {
      if(j == 0) dp[i][j] = 1;
      else dp[i][j] = 0;
    }
  }

  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= sum; ++j) {
      if(coins[i - 1] > j)
        dp[i][j] = dp[i - 1][j];
      
        else dp[i][j] = (dp[i][j - coins[i - 1]] + dp[i - 1][j])%(1000000007);
    }
  }
  printf("%d", dp[n][sum]);
}