#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

void helper(vector<int> &v, int num, vector<int> &ans) {
  int n = (int)v.size();
  for (int mask = 0; mask < (1 << n); ++mask) {
    int val = 0;
    vector<int> res;
    for (int i = 0; i < n; i++) {
      if ((mask >> i) & 1) {
        val |= v[i];
        res.push_back(i);
      }
    }
    if (val == num && (int)res.size() < (int)ans.size()) {
      ans = res;
    }
  }
}

vector<int> smallestSufficientTeam(vector<string> &skills,
                                   vector<vector<string>> &ppl) {
  int n = 0;
  unordered_map<string, int> mp;
  for (int i = 0; i < skills.size(); i++) {
    n = (n << 1) | 1;
    mp[skills[i]] = i;
  }
  vector<int> v;
  for (int i = 0; i < ppl.size(); i++) {
    int val = 0;
    for (int j = 0; j < ppl[i].size(); j++) {
      string s = ppl[i][j];
      int idx = mp[s];
      int mask = (1 << idx);
      val |= mask;
    }
    v.push_back(val);
  }
  vector<int> ans(n, 0);
  helper(v, n, ans);
  return ans;
}

int main() {}
