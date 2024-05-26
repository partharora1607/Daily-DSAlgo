class Solution {
public:
  int longestWPI(vector<int> &a) {
    int ans = 0;
    for (int i = 0; i < a.size(); i++) {
      int sum = 0;
      for (int j = i; j < a.size(); j++) {
        sum += a[j] > 8 ? 1 : -1;
        if (sum > 0)
          ans = max(ans, j - i + 1);
      }
    }
    return ans;
  }
};