#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int
class Solution {
public:
  bool divideArray(vector<int> &a) {
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size() - 1; i += 2) {
      if (a[i] != a[i + 1])
        return false;
    }
    return true;
  }
};

int main() {}
