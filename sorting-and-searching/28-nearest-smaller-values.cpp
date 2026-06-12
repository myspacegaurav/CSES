//will use stack
//traverse from the last as question demands
//we maintain a stack of numbers from right to left
//if the next element is smaller than top, we will pop

#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int>arr(n + 1), ans(n + 1);
  for(int i = 1; i <= n; ++i) cin >> arr[i];

  stack<int> st;
  for(int i = n; i >= 0; --i) {

    while(!st.empty() && arr[st.top()] > arr[i]) {
      ans[st.top()] = i;
      st.pop();
    }

    st.push(i);
  }

  for(int i = 1; i <= n; ++i) {
    cout << ans[i] << " ";
  }
}