//this is same as dice comibination
//in this we have to find the no. of ways in which we can add to sum amount 
//order matters- permutation


#include<stdio.h>
#include<stdlib.h>

#define MOD 1000000007
int *dp;

int ways(int * arr, int n, int sum) {
  if(sum == 0) return 1;
  if(n == 0) return 0;

  if(sum < 0) return 0;
  if(dp[sum] != -1) return dp[sum];

  long long w = 0;
  for(int i = 0; i < n; ++i) {
    w = (w + ways(arr, n, sum - arr[i])) % MOD;
  }
  return dp[sum] = w;
}

int main() {
  int n, sum;
  (void)scanf("%d%d", &n, &sum);

  int *coins = (int*) malloc(n * sizeof(int));

  dp = (int*) malloc((sum + 1) * sizeof(int));

  for(int i = 0; i <= sum; ++i)
      dp[i] = -1;

  for(int i = 0; i < n; ++i) (void) scanf("%d", &coins[i]);
  
  printf("%d", ways(coins, n, sum));
}