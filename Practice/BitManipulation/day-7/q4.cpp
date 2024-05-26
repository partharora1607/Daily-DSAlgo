class Solution {
public:
  vector<string> letterCasePermutation(string s) {
    unordered_map<string, int> mp;
    vector<string> v;

    int n = s.size();
    for(int i = 0 ; i < (1 << n); i++){
      string str;
      for(int j = 0 ; j < n ; j++){
        int msk = (1 << j);
        if((i & msk) == 0){
          // lowercase
          if(s[j] >= 'A' && s[j] <= 'Z'){
            str += (s[j] - 'A' + 'a');
          }
          else{
            str += s[j];
          }
        }
        else{
          // uppercase
          if(s[j] >= 'a' && s[j] <= 'z'){
            str += (s[j] - 'a' + 'A');
          }
          else{
            str += s[j];
          }
        }
      }
      mp[str]++;
    }

    for(auto it : mp){
      v.push_back(it.first);
    }

    return v;

  }
};