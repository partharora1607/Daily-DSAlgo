#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

class Solution {
public:
  vector<int> decode(vector<int> &a, int first) {
    vector<int> res = {first};
    for (int i = 0; i < a.size(); i++) {
      res.push_back(res[res.size() - 1] ^ a[i]);
    }
    return res;
  }
};
int main() {}
