#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  //n - number of applicants
  //m - number of apartments
  //k - allowed difference
  vector<int>desired(n);
  vector<int>apartment(m);

  for(int i = 0; i < n; ++i) {
    cin >> desired[i];
  }

  for(int i = 0; i < m; ++i) {
    cin >> apartment[i];
  }

  //give the minsize apartment to minsize desired
  //if apartment is small, jump to next apartment
  //if apartment is big, jump to next desired

  sort(desired.begin(), desired.end());
  sort(apartment.begin(), apartment.end());
  
  int ptr1 = 0, ptr2 = 0, count = 0;
  while(ptr1 < n && ptr2 < m) {
      if(apartment[ptr2] < desired[ptr1] - k) {
          ptr2++;
      }
      else if(apartment[ptr2] > desired[ptr1] + k) {
          ptr1++;
      }
      else {
          count++;
          ptr1++;
          ptr2++;
      }
  }
  cout << count << endl;
}