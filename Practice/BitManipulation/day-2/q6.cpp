#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

class Solution {
public:
  vector<vector<int>> flipAndInvertImage(vector<vector<int>> &v) {
    for (int i = 0; i < v.size(); i++) {
      reverse(v[i].begin(), v[i].end());
      for (int j = 0; j < v[i].size(); j++) {
        if (v[i][j] == 1)
          v[i][j] = 0;
        else
          v[i][j] = 1;
      }
    }
    return v;
  }
};

int main() {}
