//this can be a target sum problem with unbound dp
//where each item is checked with other items-permultation
//base case = target = 0 or less than 0
//we can reuse

#include<stdio.h>

long long dp[10000000];
long long mod = 1e9 + 7;
long long calc(int *arr, int n, int target) {

  if(dp[target] != -1) return dp[target];
  if(target == 0) return 1;

  if(target < 0) return 0;

  long long ways = 0;
  for(int i = 0; i < n; ++i) {
    ways = (ways + calc(arr, n, target - arr[i])) % mod;
  }
  
  return dp[target] = ways;
}

int main() {
  int target; 
  scanf("%d", &target);

  int arr[6];
  //filled with outcomes
  for(int i = 0; i < 6; ++i) arr[i] = i + 1;

  for(int i = 0; i <= target; ++i) dp[i] = -1;

  long long moves = calc(arr, 6, target);

  printf("%lld", moves);

  return 0;
}

