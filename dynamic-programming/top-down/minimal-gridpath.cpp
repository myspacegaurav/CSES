#include<iostream>
#include<vector>
#include<string>

using namespace std;
string f(vector<vector<char>>& grid, int i, int j) {
    if (i == 1 && j == 1) return string(1, grid[0][0]);
    if (i == 1) return f(grid, i, j - 1) + grid[i-1][j-1];
    if (j == 1) return f(grid, i - 1, j) + grid[i-1][j-1];

    string up   = f(grid, i - 1, j);
    string left = f(grid, i, j - 1);
    return min(up, left) + grid[i-1][j-1];
}

int main() {
  int n;
  cin >> n;
  vector<vector<char>>grid(n, vector<char>(n));

  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
      cin >> grid[i][j];

  cout << f(grid, n, n);
}