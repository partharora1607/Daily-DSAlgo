#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

class Solution {
public:
  int similarPairs(vector<string> &v) {
    // sum,cnt , freq
    map<pair<int, int>, int> mp;
    for(int i = 0 ; i < v.size(); i++){
      vector<int> freq(26);
      string s = v[i];
      for(int j = 0 ; j < s.size(); j++){
        freq[s[j] - 'a'] = 1;
      }
      int cnt = 0 , sum = 0;
      for(int j = 0 ; j < 26; j++){
        if(freq[j] == 1) {
          cnt++;
          sum++;
        }
      }
    }
  }
};

int main() {}
