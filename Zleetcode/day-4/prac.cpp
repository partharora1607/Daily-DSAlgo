#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

int main() {
  vector<int> a = {2, 7, 6, 5, 4, 3, 2, 1};
  sort(a.begin() + 1, a.begin() + 6);
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
  }
}
