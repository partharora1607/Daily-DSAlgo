#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

// Method - 1 | time : O(nlogn) | space : O(1)
vector<int> uniqueArr(vector<int> &a) {
  sort(a.begin(), a.end());

  auto it = unique(a.begin(), a.end());
  a.resize(distance(a.begin(), it));
  return a;
}

// Method - 2 | time : O(n) | space : O(n)
vector<int> uniqueArray(vector<int> &a) {
  unordered_set<int> st(a.begin(), a.end());
  a = vector<int>(st.begin(), st.end());
  return a;
}

class Solution {
public:
  int similarPairs(vector<string> &v) {
    unordered_map<string, int> mp;
    for (int i = 0; i < v.size(); i++) {
      string s = v[i];
      sort(s.begin(), s.end());
      auto it = unique(s.begin(), s.end());
      s.resize(distance(s.begin(), it));
      mp[s]++;
    }
    int cnt = 0;
    for (auto it : mp) {
      cnt += (it.second * (it.second - 1)) >> 1;
    }
    return cnt;
  }
};

int main() {}
