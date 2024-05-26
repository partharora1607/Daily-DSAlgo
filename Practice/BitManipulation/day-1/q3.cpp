class Solution {
public:
  vector<int> helper(vector<int> &a, int num) {
    // return index
    vector<int> ans;
    int n = (int)a.size();
    //   cout << "num : " << num << "\n";
    for (int i = 1; i < (1 << n); i++) {
      int my_num = 0;
      vector<int> res;
      for (int j = 0; j < n; j++) {
        if (i & (1 << j)) {
          my_num |= a[j];
          res.push_back(j);
        }
      }
      //   cout << "mynum : " << my_num << "\n";
      if (my_num == num) {
        if (ans.size() == 0)
          ans = res;
        else if ((int)res.size() < (int)ans.size())
          ans = res;
      }
    }
    return ans;
  }

  vector<int> smallestSufficientTeam(vector<string> &req_skills,
                                     vector<vector<string>> &ppl) {
    int n = req_skills.size();
    unordered_map<string, int> mp;
    for (int i = 0; i < req_skills.size(); i++)
      mp[req_skills[i]] = (1 << i);
    vector<int> a;
    for (int i = 0; i < ppl.size(); i++) {
      int num = 0;
      for (int j = 0; j < ppl[i].size(); j++)
        num |= mp[ppl[i][j]];
      // cout << num << " ";
      a.push_back(num);
    }
    int num = (1 << n) - 1;
    return helper(a, num);
  }
};
