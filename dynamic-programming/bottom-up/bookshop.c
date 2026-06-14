//if price of page is in range , take the item
//if greater dont take 
//take the page only if it is maximum in that price

#include<stdio.h>
#include<stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))


int main() {
  int n, x;
  scanf("%d%d", &n, &x);

  int *price = (int*) malloc(n * sizeof(int));
  int *page = (int*) malloc(n * sizeof(int));

  for(int i = 0; i < n; ++i) scanf("%d", &price[i]);
  for(int i = 0; i < n; ++i) scanf("%d", &page[i]);

  int **dp = (int**) malloc((n + 1)* sizeof(int*));
  for(int i = 0; i <= n; ++i) {
    dp[i] = (int*) malloc((x + 1) * sizeof(int));
  }

  //initialisation
  //if maxweight x = 0, we cannot take any pages
  for(int i = 0; i <= n; ++i) dp[i][0] = 0;
  //if there is no price array, cannot take any pages
  for(int i = 0; i <= x; ++i) dp[0][i] = 0;

  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= x; ++j) {
      if(price[i - 1] > j)
        dp[i][j] = dp[i - 1][j];
      
      else dp[i][j] = max(page[i - 1] + dp[i - 1][j - price[i - 1]],
                          dp[i - 1][j]);
    }
  }
  printf("%d", dp[n][x]);
}