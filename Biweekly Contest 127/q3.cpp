class Solution {
public:
  int minimumSubarrayLength(vector<int> &a, int k) {
    int ans = 0, j = 0, orr = 0;
    for (int i = 0; i < a.size(); i++) {
      while (orr < k) {
        orr |= a[i++];
      }
    }
  }
};