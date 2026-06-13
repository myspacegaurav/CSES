#include<stdio.h>
#include <stdlib.h>
#include<math.h>
#define min(a, b) ((a) < (b) ? (a) : (b))
int **dp;

int minimise(int *arr, int n, int sum) {
  if(n == 0) return 1000000;
  if(sum == 0) return 0;

  if(dp[n][sum] != -1) return dp[n][sum];

  if(arr[n - 1] > sum) return dp[n][sum] = minimise(arr, n - 1, sum); //skip the coin

  return dp[n][sum] = min(1 + minimise(arr, n, sum - arr[n - 1]), //reuse the coin
                      minimise(arr, n - 1, sum)); //skip the coin
}

int main() {
  int n, sum;
  scanf("%d%d", &n, &sum);
  if (n <= 0 || sum <= 0) return 1;
  dp = (int**) malloc((n + 1)* sizeof(int*));
  
  for(int i = 0; i <=n; ++i) {
    dp[i] = (int*) malloc((sum + 1)* sizeof(int));
  }
  for(int i = 0; i <= n; ++i) {
    for(int j = 0; j <=sum; ++j) {
      dp[i][j] = -1;
    }
  }


  int *coins = (int*) calloc((size_t)n, sizeof(int));
  for(int i = 0; i < n; ++i) scanf("%d", &coins[i]);

  int minWays = minimise(coins, n, sum);

  if(minWays > 1000000) printf("%d", -1);
  else printf("%d", minWays);

  return 0;
}