#include<iostream>
#include<set>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int x, n;
  cin>> x >> n;
  set<int>lamp;
  lamp.insert(0);
  lamp.insert(x);
  multiset<int>length;
  length.insert(x);

  for(int i = 0; i < n; ++i) {
    int p;
    cin >> p;
    auto r = lamp.upper_bound(p);
    auto l = r;
    --l;
    lamp.insert(p);
    int remove = *r - *l;
    int len1 = *r - p;
    int len2 = p - *l;
    length.erase(length.find(remove));

    length.insert({len1,len2});

    cout << *(--length.end()) << endl;
  }
}