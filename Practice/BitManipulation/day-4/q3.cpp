#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

// time complexity : o(1)

int OnesComplement(int n) { return n ^ (2 * ((1 << int(log2(n))) - 1) | 1); }

class Solution {
public:
  int findComplement(int num) { return OnesComplement(num); }
};

int main() {}
