#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

// all elements repeating 3 expect 1

int bit(vector<int> &a) {
  int n = (int)a.size();
  int num = 0;
  for (int i = 0; i < 32; i++) {
    int cnt = 0;
    int ok = (1 << i);
    for (int j = 0; j < n; j++) {
      if (a[j] & ok)
        cnt++;
    }
    if (cnt % 3 == 1)
      num |= ok;
  }
  return num;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int unique = bit(a);
  cout << unique << "\n";
  return 0;
}
