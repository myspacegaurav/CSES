//this is same as dice comibination
//in this we have to find the no. of ways in which we can add to sum amount 
//distinct combination needed
//so no permutation/ skip take 


#include<stdio.h>
#include<stdlib.h>

#define MOD 1000000007

int **dp;

int ways(int * arr, int n, int sum) {
  if(sum == 0) return 1;
  if(n == 0) return 0;
  
  if(sum < 0) return 0;
  if(dp[n][sum] != -1) return dp[n][sum];

  int w = 0;
  w = (ways(arr, n, sum - arr[n - 1]) + ways(arr, n - 1, sum)) % MOD;
  return dp[n][sum] = w;
}

int main() {
  int n, sum;
  scanf("%d%d", &n, &sum);

  int *coins = (int*) malloc(n * sizeof(int));

  dp = (int**) malloc((n + 1) * sizeof(int*));

  for(int i = 0; i <= n; ++i) {
    dp[i] = (int*) malloc((sum + 1) * sizeof(int));
    for(int j = 0; j <= sum; ++j)
      dp[i][j] = -1;
  }

  for(int i = 0; i < n; ++i) scanf("%d", &coins[i]);
  
  printf("%d", ways(coins, n, sum));
  return 0;
}