#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

class Solution {
public:
  vector<int> twoOutOfThree(vector<int> &nums1, vector<int> &nums2,
                            vector<int> &nums3) {
    std::bitset<101> bit1, bit2, bit3;
    for (const int &num : nums1)
      bit1.set(num);
    for (const int &num : nums2)
      bit2.set(num);
    for (const int &num : nums3)
      bit3.set(num);
    std::vector<int> ans;
    std::bitset<101> intersect = (bit1 & bit2) | (bit1 & bit3) | (bit2 & bit3);
    for (size_t i = intersect._Find_first(); i < intersect.size();
         i = intersect._Find_next(i))
      if (intersect[i])
        ans.push_back(static_cast<int>(i));
    return ans;
  }
};

int main() {}
