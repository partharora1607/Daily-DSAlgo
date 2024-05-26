class Solution {
public:
  int countTriplets(vector<int> &a) {
    int cnt = 0;
    for (int i = 0; i < a.size() - 1; i++) {
      int val = 0;
      for (int j = i + 1; j < a.size(); j++) {
        val ^= a[j - 1];
        int val2 = 0;
        for (int k = j; k < a.size(); k++) {
          val2 ^= a[k];
          if (val == val2)
            cnt++;
        }
      }
    }
    return cnt;
  }
};

// time complexity = o(n^3)