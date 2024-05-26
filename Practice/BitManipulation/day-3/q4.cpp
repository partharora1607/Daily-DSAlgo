#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

class Solution {
public:
  char repeatedCharacter(string s) {
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
      int ele = s[i] - 'a';
      int msk = (1 << ele);
      if ((ans & msk) != 0)
        return s[i];
      ans |= msk;
    }
    return 'a';
  }
};

int main() {}
