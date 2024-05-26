class Solution {
public:
  vector<int> findArray(vector<int> &pref) {
    int n = pref.size();
    vector<int> a = {pref[0]};
    int x = a[0];
    for (int i = 0; i < pref.size(); i++) {
      int new_val = x ^ pref[i];
      a.push_back(new_val);
      x ^= new_val;
    }
    return a;
  }
};