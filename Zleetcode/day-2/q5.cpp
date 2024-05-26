class Solution {
public:
  int lengthOfLastWord(string s) {
    stringstream ss(s);
    string res;
    int last = 0;
    while (getline(ss, res, ' ')) {
      if (res != "")
        last = res.size();
    }
    return last;
  }
};