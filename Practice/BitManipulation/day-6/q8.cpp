#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

// Method - 1 using maps

class Solution {
public:
  vector<int> findThePrefixCommonArray(vector<int> &a, vector<int> &b) {
    vector<int> res;
    int cnt = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < a.size(); i++) {
      mp[a[i]]++;
      if (mp[a[i]] == 2)
        cnt++;
      mp[b[i]]++;
      if (mp[b[i]] == 2)
        cnt++;
      res.push_back(cnt);
    }
    return res;
  }
};

// Method - 2

class Solution {
public:
  vector<int> findThePrefixCommonArray(vector<int> &a, vector<int> &b) {
    int n = a.size();
    vector<int> res(n);
    long long left = 0, right = 0;
    for (int i = 0; i < n; i++) {
      long long msk = (1LL << a[i]);
      left |= msk;
      msk = (1LL << b[i]);
      right |= msk;
      long long cnt = (left & right);
      res[i] = __builtin_popcountll(cnt);
    }
    return res;
  }
};

int main() {}
