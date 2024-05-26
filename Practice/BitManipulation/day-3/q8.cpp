#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

class Solution {
public:
  int hammingWeight(int n) {
    string s = bitset<32>(n).to_string();
    return count(s.begin(), s.end(), '1');
  }
};

int main() {}
