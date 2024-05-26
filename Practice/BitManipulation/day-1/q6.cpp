#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

// o (n)

class Solution {
public:
  int countTriplets(vector<int> &a) {
    // pair -> value,cnt
    unordered_map<int, pair<int, int>> mp;
    mp[0] = {0, 1};
    int xorr = 0, cnt = 0;
    for (int i = 0; i < a.size(); i++) {
      xorr ^= a[i];
      if (mp.count(xorr)) {
        int val = (i + 1) * mp[xorr].second + mp[xorr].first - mp[xorr].second;
        cnt += val;
        cout << val << "\n";
      }
      mp[xorr] = {mp[xorr].first - i - 1, mp[xorr].second + 1};
    }
    return cnt;
  }
};

// o n^2
class Solution {
public:
  int countTriplets(vector<int> &a) {
    int cnt = 0, n = a.size(), xorr1 = 0;
    for (int i = 0; i < n; i++) {
      xorr1 ^= a[i];
      int xorr2 = 0;
      for (int j = 0; j < i; j++) {
        xorr2 ^= a[j];
        if (xorr2 == xorr1)
          cnt += (i - j - 1);
      }
      if (xorr1 == 0)
        cnt += i;
    }
    return cnt;
  }
};

// o n^3
class Solution {
public:
  int countTriplets(vector<int> &a) {
    int cnt = 0;
    for (int i = 0; i < a.size() - 1; i++) {
      int val = 0;
      for (int j = i + 1; j < a.size(); j++) {
        val ^= a[j - 1];
        int val2 = 0;
        for (int k = j; k < a.size(); k++) {
          val2 ^= a[k];
          if (val == val2)
            cnt++;
        }
      }
    }
    return cnt;
  }
};
int main() {}
