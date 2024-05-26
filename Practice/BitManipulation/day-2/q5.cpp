#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

class Solution {
public:
  int countConsistentStrings(string s, vector<string> &v) {
    unordered_map<char, int> mp;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
      mp[s[i]]++;
    for (int i = 0; i < v.size(); i++) {
      string str = v[i];
      int j = 0;
      for (; j < str.size() && mp.count(str[j]) == 1;)
        j++;
      if (j == str.size())
        cnt++;
    }
    return cnt;
  }
};
int main() {}
