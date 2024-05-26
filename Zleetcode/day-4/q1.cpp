class Solution {
public:
  string makeGood(string s) {
    string str;
    for (int i = 0; i < s.size(); i++) {
      if (str.size() == 0)
        str += s[i];
      else if (tolower(str.back()) == tolower(s[i]) && str.back() != s[i])
        str.pop_back();
      else
        str += s[i];
    }
    return str;
  }
};