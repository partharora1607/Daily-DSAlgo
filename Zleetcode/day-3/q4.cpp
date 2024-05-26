class Solution {
public:
  vector<string> helper(int n) {
    if (n == 1)
      return {"0", "1"};
    vector<string> v = helper(n - 1);
    vector<string> ans;
    for (int i = 0; i < v.size(); i++) {
      ans.push_back("0" + v[i]);
    }
    for (int i = v.size() - 1; i >= 0; i--) {
      ans.push_back("1" + v[i]);
    }
    return ans;
  }

  vector<int> grayCode(int n) {
    vector<string> binary = helper(n);
    vector<int> ans;
    for (int i = 0; i < binary.size(); i++) {
      ans.push_back(stoi(binary[i], nullptr, 2));
    }
    return ans;
  }
};