#include<stdio.h>

int main() {
  int n;
  scanf("%d", &n);

  int arr[1000000];
  arr[0] = 1;
  int mod = 1e9 + 7;

  for(int i = 1; i <= n; ++i) {
    arr[i] = 0;
    for(int j = 1; j <= 6; ++j) {
      if(i - j >= 0) {
        arr[i] = (arr[i] + arr[i - j]) % mod;
      }
    }
  }
  printf("%d", arr[n]);
  return 0;
}